#include "BSTree.h"

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

///////////////////////////////////
// Already Implemented Functions //
///////////////////////////////////

// These functions are already implemented for you. Scroll below to
// see the functions that you have to implement 


// constructors
BSTree::BSTree() : size(0), root(nullptr) {}

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree) {
    tree.print_level_by_level(out);
    return out;
}

ostream& operator<<(ostream& out, Node& node) {
    return out << node.value << "[" << node.search_time << "]";
}

istream& operator>>(istream& in, BSTree& tree) {
  /*
  take input from the in stream, and build your tree
  input will look like
  4 
  2 
  6 
  1 
  3 
  5 
  7
  */
  int next;
  while(in >> next) {
    tree.insert(next);
  }
  return in;
}

// Example recursive function
void BSTree::copy_helper(Node*& newNode, const Node* sourceNode) {
    //Don't copy if the node is nullptr
    if(sourceNode == nullptr) return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode->value);
    //Copy over the search cost
    newNode->search_time = sourceNode->search_time;

    //Copy left subtree
    if (sourceNode->left != nullptr) copy_helper(newNode->left, sourceNode->left);
    //Copy right subtree
    if(sourceNode->right != nullptr) copy_helper(newNode->right, sourceNode->right);
}

// recursive function
int BSTree::get_total_search_time(Node* node) {
  if (node != nullptr) {
    return node->search_time + get_total_search_time(node->left) + get_total_search_time(node->right);
  }
  return 0;
}

// implemented
float BSTree::get_average_search_time() {
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;
	
  return ((float)total_search_time)/size;
}


///////////////////////////////////
//     Functions to Implement    //
///////////////////////////////////

// These are the functions you should implement
// Feel free to call the functions above or create new helper functions

// copy constructor
BSTree::BSTree(const BSTree& other) {
  if (other.root!=nullptr) { // if other list not null, destroy and copy over
    copy_helper(root, other.root);
    size = other.size;
    return;
  }
  else root = nullptr;
}

// move constructor
BSTree::BSTree(BSTree&& other) {
  size = other.size;
  root = other.root;
  other.root = nullptr;
  other.size = 0;
}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other) {
  if (this != &other && other.root) {
    copy_helper(root, other.root);
    size = other.size;
    return *this;
  } else if (this!=&other && !other.root) {
    size = 0;
    root = nullptr;
  }

  return *this;
}

// move assignment
BSTree& BSTree::operator=(BSTree&& other) {
  if (this!=&other) {
    std::swap(root, other.root);
    size = other.size;
    destroy(other.root);
    other.root = nullptr;
    other.size = 0;
  }
  return *this;
}

void BSTree::destroy(Node * N1) {
  if (N1) {
    destroy(N1->left);
    destroy(N1->right);
    delete N1;    
  }
}

// destructor
BSTree::~BSTree() {
  destroy(root);
}

// insert node into correct position in tree
Node* BSTree::insert(int obj) {
  Node * newNode = new Node (obj);
  Node * find = root;
  Node * prev = nullptr;
  int sTime = 1;
  while (find != nullptr) {
    prev = find;
    if (obj < find->value) {
      find = find->left;
      sTime++;
    }
    else {
      find = find->right;
      sTime++;
    }
  }
  
  if (prev == nullptr)  {
    newNode->search_time = sTime;
    size++;
    root = newNode;
  }
  else if (obj < prev->value) {
    prev->left = newNode;
    size++;
    newNode->search_time = sTime;
  }
  else {
    prev->right = newNode;
    size++;
    newNode->search_time = sTime;
  }
  return newNode;
    /* insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node */
}

Node * BSTree::search_helper(Node * howdy, int obj) {
  if (howdy == nullptr || howdy->value == obj) return howdy;
  if (howdy->value < obj) return search_helper(howdy->right, obj);
  return search_helper(howdy->left, obj);
}

Node* BSTree::search(int obj) {
  return search_helper(root, obj);
}

void BSTree::update_search_times() {
  if (root == nullptr) return;
  queue <Node *> dog;
  dog.push(root);
  int level = 1;
  while (!dog.empty()) {
    int nodeCt = dog.size();
    while (nodeCt > 0) {
      Node * iter = dog.front();
      iter->search_time = level;
      dog.pop();
      if (iter->left) dog.push(iter->left);
      if (iter->right) dog.push(iter->right);
      nodeCt--;
    }
    level++;
  }
  


    /* do a BFS or DFS of your tree and update the search times of all nodes at once
    The root has a search time of 1, and each child is 1 more than its parent */
}

// string BSTree::inorder_helper(Node * iter, string curr) {
//   if (iter == nullptr) return "";
//   inorder_helper(iter->left, curr);
//   string howdy = *iter;
//   curr += ;
//   inorder_helper(iter->right);
// }

void BSTree::inorder(ostream& out) {
  stack<Node*> heck;
  Node * iter = root;
  while (!heck.empty()|| iter != nullptr) {
    if (iter != nullptr) {
      heck.push(iter);
      iter = iter->left;
    } else {
      iter = heck.top();
      heck.pop();
      out << *iter << " ";
      iter = iter->right;
    }
  }
    

    /* print your nodes in infix order
    If our tree looks like this:

       4
     2   6
    1 3 5 7

    It should output:
    1[3] 2[2] 3[3] 4[1] 5[3] 6[2] 7[3]
    You can use the << operator to print the nodes in the format shown */
}

void BSTree::print_level_by_level(ostream& out) {
  queue <Node *> Q2;
  Q2.push(root);
  int elementsInLevel = 1;
  bool nonNullChild = false;
  while (elementsInLevel > 0) {
    Node * iter = Q2.front();
    Q2.pop();
    elementsInLevel--;
    if (iter) {
      out << *iter;
      Q2.push(iter->left);
      Q2.push(iter->right);
      if (iter->left||iter->right) nonNullChild = true;
    } else {
      out << " X";
      Q2.push(nullptr);
      Q2.push(nullptr);
    }
    if (elementsInLevel == 0) {
      out << endl;
      if (nonNullChild) {
        nonNullChild = false;
        elementsInLevel = Q2.size();
      }
    }
  }

  
    /* Print the tree using a BFS so that each level contains the values for a level of the tree.
    Use X to mark empty positions. 
    
      if our tree looks like this:

       4
     2   6
    1   5 7
           9

    it should output:

    4[1]
    2[2] 6[2]
    1[3] X 5[3] 7[3]
    X X X X X X X 9[4]

    it might be helpful to do this part with the std::queue data structure.
    Hint: the Nth level contains 2^(N-1) nodes (with a value or with an X). Watch out
    for nodes like the left child of 6 above, and print the descendents of an empty
    node as also empty
    You can use the << operator to print nodes in the format shown */
}
