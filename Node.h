#pragma once
#include <memory>

template <typename T> class Node {
public:
  Node(T parameter);
  T value;
  std::shared_ptr<Node<T>> next;
};

template <typename T> Node<T>::Node(T value) : value(value), next(nullptr) {}
