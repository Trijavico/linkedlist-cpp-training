#include "LinkedList.h"
#include "Node.h"
#include <cstddef>
#include <iostream>

using namespace std;

LinkedList::LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}

LinkedList::~LinkedList() {
  Node *current = _head;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }
}

size_t LinkedList::GetSize() { return _size; }

void LinkedList::Print() {
  Node *current = _head;
  size_t counter = 1;

  while (current != nullptr) {
    cout << counter << ". " << current->value << endl;
    current = current->next;
    counter++;
  }
}

void LinkedList::Add(Node *node) {
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

void LinkedList::Update(int value, int newValue) {
  Node *current = _head;
  while (current != nullptr) {
    if (current->value != value) {
      current = current->next;
      break;
    }

    current->value = newValue;
  }
}

void LinkedList::Remove(int value) {
  Node *current = _head;
  Node *prev = nullptr;

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
