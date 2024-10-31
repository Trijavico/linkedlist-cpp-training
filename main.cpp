#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  LinkedList<std::string> list;

  list.Add("one");
  list.Add("two");
  list.Add("three");
  list.Add("four");

  list.Print();
  cout << endl;

  list.Update("one", "ten");
  list.Print();
  cout << endl;

  list.Remove("two");
  list.Print();
}
