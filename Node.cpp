//
// Created by Lawrence Degoma on 5/30/24.
//

#include "Node.h"

template <typename T>
Node<T>::Node(int t, bool leaf){
    degree = t;
    is_leaf = leaf;
    keys = new T[2 * t - 1];
    children = new Node*[2 * t];
    n=0;
}

template <typename T>
Node<T>::~Node(){
    delete[] keys;
    delete[] children;
}
