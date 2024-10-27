
#include "Node.h"

Node::Node(int value) : value(value), next(nullptr) {}
Node::~Node() { delete next; }
