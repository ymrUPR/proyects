#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


// BHNode class:
// The nodes of the binary heap are objects of this class.

class BHNode {
public:
  int key;
  BHNode *left, *right, *parent;
  BHNode(int k = 0, BHNode *l = NULL, BHNode *r = NULL, BHNode *p = NULL):
    key(k), left(l), right(r), parent(p) {}
  bool isLeaf() const { return left == NULL && right == NULL; }
};

class BinMaxHeap {
private:
  BHNode *root;   // a pointer to the root node of the heap
  int n;          // the number of nodes in the heap

  // Given a pointer to the node, will percolate up 
  void percolateUp(BHNode *p);

  void percolateDown(BHNode *p);

  void toString(string &st, BHNode *cur, int dist) const;

public:

  // a constructor
  BinMaxHeap();

  // Insert the key k in the heap
  void insert(int k);

  // Remove the root from the heap
  void pop();

  // Get the key from the root
  void top() const;

  //Get the binary number of size n
  vector<int> binarifier(int n);

  //BHNode* lastNode(vector<int>v1, BHNode *root);

  string preOrder(BHNode *r) const;

  string preOrder() const;

  string toString() const;

};


  

