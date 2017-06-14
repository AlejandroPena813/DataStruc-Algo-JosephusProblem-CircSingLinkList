#ifndef _CSLL_H_
#define _CSLL_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

template <typename T>
class CSLL {

  private:
    struct Node{
      T x;
      Node *next;
    }; 

    Node* head;

    int sizeOfList;

    Node* traverse_list(int position);

  public:
    CSLL();

    ~CSLL();

    void insert(const T& element, int position);

    T remove( int position);

    T item_at( int position);

    ostream& print(ostream& out);



};

#endif
