//
// Created by hacker on 21.01.2021.
//
// Copyright 2021 hacker
#include "Stack.hpp"
#include <cstdlib>
#include <iostream>
#include <type_traits>
#ifndef TEMPLATE_NOCOPYABLESTACK_HPP
#define TEMPLATE_NOCOPYABLESTACK_HPP
template <typename T>
class NoCopyableStack{
   public:
    NoCopyableStack();
    explicit NoCopyableStack(const NoCopyableStack& stack) = delete;
    NoCopyableStack(NoCopyableStack&& stack) noexcept = default;
    auto operator=(NoCopyableStack&& stack) noexcept -> NoCopyableStack& =
        default;
    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(T&& value);
    const T& head() const;
    T pop();
    ~NoCopyableStack();
 private:
  Element<T> *_head;
};
template <typename T>
NoCopyableStack<T>::NoCopyableStack():_head(nullptr){
  if (std::is_copy_constructible<T>::value ||
      std::is_copy_assignable<T>::value ||
      !(std::is_move_constructible<T>::value ||
        std::is_move_assignable<T>::value))
    throw std::runtime_error("Error stack");
                                        }
template <typename T>
void NoCopyableStack<T>::push(T&& value) {
  _head = new Element<T> {std::forward<T>(value), _head};
}
template <typename T>
template <typename... Args>
void NoCopyableStack<T>::push_emplace(Args&&... value) {
  _head = new Element<T>{{std::forward<Args>(value)...}, _head};
}

template <typename T>
const T& NoCopyableStack<T>::head() const {
  if (!_head) throw std::runtime_error("Empty stack");
  return _head->data; }

template <typename T>
T NoCopyableStack<T>::pop() {
  if (_head){
    auto* buf = _head;
    T data = std::move(_head->data);
    _head = _head -> prev;
    delete buf;
    return data;
  }else {
    throw std::runtime_error("Empty stack");
  }
}

template <typename T>
NoCopyableStack<T>::~NoCopyableStack() {
  while (_head){
    Element<T> *_head1 = _head->prev;
    delete _head;
    _head = _head1;
  }
}
#endif  // TEMPLATE_NOCOPYABLESTACK_HPP
