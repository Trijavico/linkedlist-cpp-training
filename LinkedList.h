#pragma once
#include "Node.h"
#include <cstddef>
#include <iostream>
#include <memory>

template <typename T> class LinkedList {
public:
  LinkedList();

  size_t GetSize();

  void Print();
  void Add(T value);
  void Remove(T value);
  void Update(T value, T newValue);

private:
  std::shared_ptr<Node<T>> _head;
  std::shared_ptr<Node<T>> _tail;
  size_t _size;
};

template <typename T>
LinkedList<T>::LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}

template <typename T> size_t LinkedList<T>::GetSize() { return _size; }

template <typename T> void LinkedList<T>::Add(T value) {
  std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(value);

  if (_head == nullptr) {
    _head = node;
    _tail = node;
    _size++;
    return;
  }

  node->next = _head;
  _head = node;
  _size++;
}

template <typename T> void LinkedList<T>::Print() {
  std::shared_ptr<Node<T>> current = _head;
  size_t counter = 1;

  while (current != nullptr) {
    std::cout << counter << ". " << current->value << std::endl;
    current = current->next;
    counter++;
  }
}

template <typename T> void LinkedList<T>::Update(T value, T newValue) {
  std::shared_ptr<Node<T>> current = _head;
  while (current != nullptr) {
    if (current->value != value) {
      current = current->next;
      continue;
    }

    current->value = newValue;
    break;
  }
}

template <typename T> void LinkedList<T>::Remove(T value) {
  if (!_head) {
    return;
  }

  if (_head->value == value) {
    _head = _head->next;
    if (!_head) {
      _tail.reset();
    }
    _size--;
    return;
  }

  std ::shared_ptr<Node<T>> current = _head;
  std::shared_ptr<Node<T>> prev = nullptr;

  while (current != nullptr) {
    if (current->value == value) {
      prev->next = current->next;

      if (current == _tail) {
        _tail = prev;
      }

      _size--;
      return;
    }

    prev = current;
    current = current->next;
  }
}
