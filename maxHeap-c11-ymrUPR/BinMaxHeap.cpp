#include "BinMaxHeap.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

BinMaxHeap::BinMaxHeap() {
  root = NULL;
  n = 0;
}

void BinMaxHeap::percolateUp(BHNode *p) {

  if((p && p->parent) && (p->parent->key < p->key)){
    swap(p->key, p->parent->key);
    return percolateUp(p->parent);
  }
}

void BinMaxHeap::percolateDown(BHNode *p){ 
  if(p && p->parent && p->parent->key < p->key)
    swap(p->parent->key, p->key);
    
  if(p->left && p->right)
    return percolateDown(p->left->key < p->right->key ? p->right : p->left);

  else if(p->left)
    percolateUp(p->left);

  else if(p->right)
    percolateDown(p->right);
}

vector<int> BinMaxHeap::binarifier(int n){
 vector<int>v1;
  int size = n;
  for(int i = 0; size > 0; i++){
    v1.push_back(size%2);
    size /= 2;
  }
  reverse(v1.begin(), v1.end());
  return v1;
}

/*BHNode* BinMaxHeap::lastNode(vector<int>v1, BHNode *root){
 int count = 0;
 BHNode *temp = root;
 while(count <= v1.size()){
   if(v1[count] == 0){
     count++;
     temp = temp->left;
   }

   else{
     count++;
     temp = temp->right;
   }
 }

 return temp;
}*/


void BinMaxHeap::insert(int k) {
  auto newNode = new BHNode;
  newNode->key = k;

  if(!root){ 
    n++;
    root = newNode;}
  else {
    n++;
    auto parent = root;
    auto v = binarifier(n);
    for(auto i = 1; i+1 < v.size(); i++){ 
      parent = !v[i] ? parent->left : parent->right;}
    newNode->parent = parent;
    (!parent->left ? parent->left : parent->right) = newNode;
  }
  percolateUp(newNode);
}

void BinMaxHeap::pop() {
 // if null yeet out of function
  if(n == 1){
    n--;
    delete root;
    root = NULL;
  }
  if(!root) return;

  auto parent = root;
  auto v = binarifier(n);
  for(auto i = 1; i + 1 < v.size(); i++) parent = !v[i] ? parent->left : parent->right;

  BHNode* delNode;
  // pick node to be deleted, null pointer from parent
  if(parent->right) {
    delNode = parent->right;
    parent->right = NULL;
  } else {
    delNode = parent->left;
    parent->left = NULL;
  }

  // swap value with root
  root->key = delNode->key;

  // delete node
  delete delNode;
  n--;

  percolateDown(root);
}


void BinMaxHeap::top() const {
  if(!root)
    cout << "The heap is empty, there is no top!" << endl;
  else
    cout << "The top: " << root->key << endl;
  

}


void BinMaxHeap::toString(string &st, BHNode *cur, int dist) const{
  if (cur) {
      if (cur->right) toString(st, cur->right, dist + 1);
      for (int i = 0; i < dist; i++) st += "    ";
      st = st + to_string(cur->key)  + "\n";
      if (cur->left) toString(st, cur->left, dist + 1);
  }
}

string BinMaxHeap::toString() const {
    string st;
    toString(st, root, 0);
    return st;
}


  string BinMaxHeap::preOrder(BHNode *r) const {
    if (!r) return "";
    string left = preOrder(r->left);
    string right = preOrder(r->right);
    return to_string(r->key) + (left.length() > 0 ? " " + left: left)   + "" +  (right.length() > 0 ? " " + right: right);
  }
  string BinMaxHeap::preOrder() const {
    return preOrder(root);
  }