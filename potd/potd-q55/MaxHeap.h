#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include "vector"
#include <algorithm>
#include <limits>
using namespace std;

class MaxHeap
{
  public:
    /**
    * @elements: stores the integers in the heap.
    */
    vector<int> elements;

    /**
    * @heapifyDown: performs heapifyDown algorithm starting from index all the
    *   way down the heap.
    */
    void heapifyDown(int index);

    /**
    * @heapifyUp: performs heapifyUp algorithm starting from index all the way
    *   up the heap.
    */
    void heapifyUp(int index);

    /**
    * @buildHeap: this is the buildHeap algorithm. It is called when a new heap
    *   object is created.
    */
    void buildHeap();

    /**
    * Constructor: constructs a MaxHeap from the given integer vector.
    */
    MaxHeap(const vector<int> & vector);

    /**
    * Empty constructor: constructs an empty MaxHeap.
    */
    MaxHeap();

    /**
    * @insert: inserts an integer into the MinHeap.
    */
    void insert(int newValue);

    /**
    * @peek: returns the value of the element at the top of the heap. Does not
    *   modify the heap.
    */
    int peek() const;

    /**
    * @pop: returns the value of the element at the top of the heap and removes
    *   it from the heap.
    */
    int pop();

    /**
    * @print: prints out the array of elements in the heap.
    */
    void print() const;
};

#endif // MAXHEAP_H
