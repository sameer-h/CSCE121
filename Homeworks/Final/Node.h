// Node.h
#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
  T data;
  Node* next;
  
  Node() : next(nullptr) {}
  Node(T val) : data(val), next(nullptr) {}
};

#endif