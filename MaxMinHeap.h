#ifndef MAXMIN
#define MAXMIN
#include "Heap.h"
class MaxMinHeap: public Heap{
public:
  MaxMinHeap();
  ~MaxMinHeap();
  void buildHeap(int* input, int size);
  void insert(int x);
  void deleteMin();
  void deleteMax();
  int findMin();
  int findMax();
  void levelOrder();

  int getParent(int i);
  int* getChildrenIndices(int i);
  bool isMax(int i);

  void heapify(int i);

};
#endif