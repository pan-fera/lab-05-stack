//
// Created by hacker on 16.01.2021.
//r
#include <cstdlib>
#include <iostream>
#include <type_traits>
#ifndef TEMPLATE_STACK_HPP
#define TEMPLATE_STACK_HPP
template <typename T>
struct Element
{
  const T data;
  Element *prev;
  Element *next;
};
template <typename T>
class Stack
{
 public:
  Stack():_head(nullptr){};
  explicit Stack(const Stack& stack) = delete;
  Stack(Stack&& stack) = default;
  auto operator=(Stack&& stack) -> Stack& = default;
  [[maybe_unused]] void push(T&& value);
  [[maybe_unused]] void push(const T& value);
  [[maybe_unused]] void pop();
  [[maybe_unused]] const T& head() const;
  virtual ~Stack();
 private:
  Element<T> *_head;
};
template <typename T>
void Stack<T>::push(T&& value) {
  Element<T> *object = new Element<T> {value, _head, nullptr};

  if ( _head )
    _head->next = object;
  _head = object;
}
template <typename T>
void Stack<T>::push(const T& value) {
  Element<T> *object = new Element<T> {value, _head, nullptr};

  if ( _head )
    _head->next = object;
  _head = object;
}
template <typename T>
void Stack<T>::pop() {
  if (_head){
    Element<T> *_head1 = _head->prev;
    delete _head;
    _head = _head1;
    if (_head) _head->next = nullptr;
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
