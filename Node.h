#pragma once

template <typename T> class Node {
public:
  Node(T parameter);
  T value;
  Node *next;
};

template <typename T> Node<T>::Node(T value) : value(value), next(nullptr) {}
