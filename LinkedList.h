#pragma once
#include "Node.h"
#include <cstddef>
#include <iostream>

template <typename T> class LinkedList {
public:
  LinkedList();
  ~LinkedList();

  size_t GetSize();

  void Print();
  void Add(T value);
  void Remove(T value);
  void Update(T value, T newValue);

private:
  Node<T> *_head;
  Node<T> *_tail;
  size_t _size;
};

template <typename T>
LinkedList<T>::LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}

template <typename T> LinkedList<T>::~LinkedList() {
  Node<T> *current = _head;
  while (current != nullptr) {
    Node<T> *next = current->next;
    delete current;
    current = next;
  }
}

template <typename T> size_t LinkedList<T>::GetSize() { return _size; }

template <typename T> void LinkedList<T>::Print() {
  Node<T> *current = _head;
  size_t counter = 1;

  while (current != nullptr) {
    std::cout << counter << ". " << current->value << std::endl;
    current = current->next;
    counter++;
  }
}

template <typename T> void LinkedList<T>::Add(T value) {
  Node<T> *node = new Node(value);

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

template <typename T> void LinkedList<T>::Update(T value, T newValue) {
  Node<T> *current = _head;
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
  Node<T> *current = _head;
  Node<T> *prev = nullptr;

  while (current != nullptr) {
    if (_head->value == value) {
      if (_size == 1) {
        _head = nullptr;
        _tail = nullptr;
        delete current;
      }

      _head = _head->next;
      current->next = nullptr;
      delete current;
      break;
    }

    if (current->value != value) {
      prev = current;
      current = current->next;
      continue;
    }

    if (current == _tail) {
      _tail = prev;
      delete current;
      break;
    }

    prev->next = current->next;
    current->next = nullptr;
    delete current;
    break;
  }

  _size--;
}
