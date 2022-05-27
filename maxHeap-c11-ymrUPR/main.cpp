//Yadiel Mercado Rivera
//801195597
#include <iostream>
#include "ccom3034.h"
#include "BinMaxHeap.h"

int main() {
  BinMaxHeap h;
  
  h.top();
  h.insert(12);
  h.insert(42);
  h.insert(33);
  expect(h.preOrder() == "42 12 33");

  h.top(); //Should say 42
  h.pop(); //Testing pop functionality
  expect(h.preOrder() == "33 12");

  h.top(); //Should say 33
  h.pop(); //Once again testing pop
  expect(h.preOrder() == "12");

  h.pop(); //Testing pop when it's deleting last element
  h.top(); //Should say there's an empty heap.





    // PRUEBAS DEL PROFE

  cout << "\n\n=======PRUEBAS DEL PROFE=======\n\n";
  BinMaxHeap prof01, prof02, prof03;

  for(int i = 10; i >= 1; i--)
   prof01.insert(i);

  //cout << "Got: " << prof01.preOrder() << "\n";
  expect(prof01.preOrder() == "10 9 7 3 2 6 1 8 5 4");
  
  // expect(prof01.top() == 10);
  prof01.pop();
  // cout << "Got: " << prof01.preOrder() << "\n";
  expect(prof01.preOrder() == "9 7 3 1 2 6 8 5 4");

  for(int i = 1; i <= 10; i++) prof02.insert(i);
  // cout << "Got: " << prof02.preOrder() << "\n";
  expect(prof02.preOrder() == "10 9 7 1 4 8 3 6 2 5");

  for(int i = 1; i <= 5; i++) { prof03.insert(5 + i); prof03.insert(5 - i); }
  // cout << "Got: " << prof03.preOrder() << "\n";
  expect(prof03.preOrder() == "10 9 7 1 3 4 0 8 2 6");
  }