#ifndef DISJOINT_SET_DISJOINT_SET_H
#define DISJOINT_SET_DISJOINT_SET_H

#include <iostream>
using namespace std;

class disjoint_set {
private:
    int *rank, *parent, n;

    // Creates n single item sets
    void makeSet() {
      for (int i = 0; i < n; i++) {
        parent[i] = i;
      }
    }
public:
    // Default constructor
    disjoint_set() = default;

    // Constructor to create and initialize sets of n items
    disjoint_set(int n) {
      rank = new int[n];
      parent = new int[n];
      this->n = n;
      makeSet();
    }

    // Finds set of given item x
    int find(int x) {
      // Finds the representative of the set that x is an element of
      if (parent[x] != x) {

        // if x is not the parent of itself Then x is not the representative of his set,
        parent[x] = find(parent[x]);

        // so we recursively call Find on its parent and move I's node directly under the representative of this set
      }

      return parent[x];
    }

    // Do union of two sets represented by x and y.
    void Union(int x, int y) {
      // Find current sets of x and y
      int xSet = find(x);
      int ySet = find(y);

      // If they are already in same set
      if (xSet == ySet)
        return;

      // Put smaller ranked item under bigger ranked item if ranks are different
      if (rank[xSet] < rank[ySet]) {
        parent[xSet] = ySet;
      } else if (rank[xSet] > rank[ySet]) {
        parent[ySet] = xSet;
      } else { // If ranks are same, then increment rank.
        parent[ySet] = xSet;
        rank[xSet]++;
      }
    }
};

#endif //DISJOINT_SET_DISJOINT_SET_H
