//
// Created by hacker on 16.01.2021.
//
// Copyright 2021 hacker
#include <cstdlib>
#include <iostream>
#include <type_traits>
#ifndef TEMPLATE_STACK_HPP
#define TEMPLATE_STACK_HPP
template <typename T>
struct Element
{
  T data;
  Element *prev;
};
template <typename T>
class Stack
{
 public:
  Stack():_head(nullptr){};
  explicit Stack(const Stack& stack) = delete;
  Stack(Stack&& stack)  noexcept = default;
  auto operator=(Stack&& stack)  noexcept -> Stack& = default;
  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;
  ~Stack();
 private:
  Element<T> *_head;
};
template <typename T>
void Stack<T>::push(T&& value) {
  _head = new Element<T> {value, _head};
}
template <typename T>
void Stack<T>::push(const T& value) {
  _head = new Element<T> {value, _head};
}
template <typename T>
void Stack<T>::pop() {
  if (_head){
    Element<T> *_head1 = _head->prev;
    delete _head;
    _head = _head1;
  }else {
    throw std::runtime_error("Empty stack");
  }
}
template <typename T>
const T& Stack<T>::head() const {
  if (!_head) throw std::runtime_error("Empty stack");
  return _head->data; }
template <typename T>
Stack<T>::~Stack() {
  while (_head){
    Element<T> *_head1 = _head->prev;
    delete _head;
    _head = _head1;
  }
}

#endif  // TEMPLATE_STACK_HPP
