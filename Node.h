//
// Created by Lawrence Degoma on 5/30/24.
//

#ifndef BTREES_NODE_H
#define BTREES_NODE_H

template <typename T>
struct Node {
    T* keys;
    int degree;
    Node** children;
    int n;
    bool is_leaf;

    Node(int t, bool leaf);
    ~Node();
};

#include "Node.cpp"

#endif //BTREES_NODE_H
