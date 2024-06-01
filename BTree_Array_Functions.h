//
// Created by Lawrence Degoma on 5/30/24.
//

#ifndef BTREES_BTREE_ARRAY_FUNCTIONS_H
#define BTREES_BTREE_ARRAY_FUNCTIONS_H

template <class T>
void split(T data1[], int& n1, T data2[], int& n2);

template <class T>
void insert_item(T data[], int i, int& n, T entry);

template <class T>
void detach_item(T data[], int& n, T& entry);

#include "BTree_Array_Functions.cpp"
#endif //BTREES_BTREE_ARRAY_FUNCTIONS_H
