#ifndef MINMAX
#define MINMAX
#include "Heap.h"
class MinMaxHeap: public Heap{
public:
  MinMaxHeap();
  ~MinMaxHeap();
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