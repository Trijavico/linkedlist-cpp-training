#pragma once
#include "Node.h"
#include <cstddef>

class LinkedList {
public:
  LinkedList();
  ~LinkedList();

  size_t GetSize();

  void Print();
  void Add(Node *node);
  void Remove(int value);
  void Update(int value, int newValue);

private:
  Node *_head;
  Node *_tail;
  size_t _size;
};
