#include "MinMaxHeap.h"
#include <math.h>
#include <iostream>
//allocate array of size 500 to store complete BT
MinMaxHeap::MinMaxHeap(){
    this->arr = new int[500];
    for(int i =0;i<500;i++){
      arr[i] = -1;
    }
    this->size = 0;
}
//free MinMaxHeap storage
MinMaxHeap::~MinMaxHeap(){
    delete [] this->arr;
}
//insert elements of input into array to form a complete BT, then modify it to obey heap property
void MinMaxHeap::buildHeap(int* input, int size){
    this->size = size;
    for(int i=0;i<size;i++){
      this->arr[i] = input[i];
      heapify(i);
    }
}
//insert an item into the min heap, maintaining heap property.
void MinMaxHeap::insert(int x){
  if(arr[1]==-1){
    arr[1] = x;
    return;
  }
  for(int i=499;i>=2;i--){
    if(arr[i-1]!=-1 && arr[i]==-1){
      arr[i] = x;
      heapify(i);
      break;
    }
  }
  this->size++;
}
//delete the minimum element by replacing the root with the last element and heapifying
void MinMaxHeap::deleteMin(){

}
//find the maximum element among the MaxMinHeap's leaves and delete it, maintaining heap property
void MinMaxHeap::deleteMax(){
}
//return the root
int MinMaxHeap::findMin(){
    return arr[1];

}
//search the leaves for the maximum element
int MinMaxHeap::findMax(){

}
//print the heap's elements by level
void MinMaxHeap::levelOrder(){
  if(arr[1] == -1) return;
  std::cout << "1: " << arr[1] << "\n";
  std::cout << "2: ";
  for(int i =2;i<4;i++){
      if(arr[i] == -1) return;
      std::cout << arr[i] << " ";
  }
  std::cout << "\n";
  for(int i = 1; pow(2, i)<500;i++){
      if(arr[i] == -1) return;
      std::cout << i+2 << ": ";
      for(int j = pow(2, i)+1; j<pow(2, i+1);j++){
          if(arr[j] == -1) return;
          std::cout << arr[j] << " ";
      }
      std::cout << "\n";
  }
  std::cout << "\n";

}

//get the parent index of an individual node
int MinMaxHeap::getParent(int i){
    return floor((i-1)/2);
}

//get an array of the 0-5 children of an individual node
int* MinMaxHeap::getChildrenIndices(int i){
    int* children = new int[2];
    for(int j=1;j<=2;j++){
      children[j-1] = 2*i+j;
    }
    return children;
}

bool MinMaxHeap::isMax(int i){
  int level = floor(log2(i));
  return (level%2 == 0);
}

void MinMaxHeap::heapify(int insertedIndex){
    bool bottomIsMax = isMax(insertedIndex);
    int insertedVal = arr[insertedIndex];
    int parentIndex = getParent(insertedIndex);
    int parentVal = arr[parentIndex];

    if(insertedVal == parentVal) return;

    if(insertedVal<parentVal){
      int currVal = insertedVal;
      int currIndex = insertedIndex;
      //compare with min nodes
      int currCompIndex;
      if(bottomIsMax){
        currCompIndex = parentIndex;
      }
      else{
        currCompIndex = getParent(parentIndex);
      }
      while(currCompIndex>0 && currVal<arr[currCompIndex]){
        //swap up while less than previous min node
        int tmp = arr[currCompIndex];
        arr[currCompIndex] = currVal;
        arr[currIndex] = tmp;

        currIndex = currCompIndex;
        currVal = arr[currIndex];
        currCompIndex = getParent(getParent(currCompIndex));
      }
    }
    else if (insertedVal>parentVal){
      int currVal = insertedVal;
      int currIndex = insertedIndex;
      int currCompIndex;

      //compare with max nodes
      if(bottomIsMax){
        currCompIndex = getParent(parentIndex);
      }
      else{
        currCompIndex = parentIndex;
      }
      while(currCompIndex>0 && currVal>arr[currCompIndex]){
        int tmp = arr[currCompIndex];
        arr[currCompIndex] = currVal;
        arr[currIndex] = tmp;

        currIndex = currCompIndex;
        currVal = arr[currIndex];
        currCompIndex = getParent(getParent(currCompIndex));
      }
    }
}