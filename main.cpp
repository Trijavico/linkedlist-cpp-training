#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main() {
  Node *one = new Node(1);
  Node *two = new Node(2);
  Node *three = new Node(3);
  Node *four = new Node(4);

  LinkedList list;

  list.Add(one);
  list.Add(two);
  list.Add(three);
  list.Add(four);

  list.Print();
}
