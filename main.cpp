#include <iostream>
#include "disjoint_set.h"

int main() {
  disjoint_set ds(5);

  bool answer = ds.find(0) == ds.find(2);
  cout << (answer? "0 and 2 are in the same subset": "0 and 2 aren't in the same subset") <<"\n";

  ds.Union(0, 2);

  answer = ds.find(0) == ds.find(2);
  cout << (answer? "0 and 2 are in the same subset": "0 and 2 aren't in the same subset");

  return 0;
}