//
// Created by Lawrence Degoma on 5/30/24.
//

#ifndef BTREES_BTREE_H
#define BTREES_BTREE_H

#include "BTree_Array_Functions.h"
#include <iostream>
#include "Node.h"

template <typename T>
class BTree {
private:
    void insert_non_full(Node<T>* node, const T& key);
    void split_child(Node<T>* node, int i);
    void print(Node<T>* node, std::ostream &out, int depth) const;
    
    Node<T>* root;
    int t; // minimum degree

public:
    BTree(int min_degree = 2);
    ~BTree();

    void insert(const T& key);
    void print(std::ostream &out = std::cout) const;
};

#include "BTree.cpp"
#endif //BTREES_BTREE_H
