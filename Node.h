#pragma once

class Node {
public:
  Node(int parameter);
  ~Node();
  int value;
  Node *next;
};
