//
// Created by Lawrence Degoma on 5/30/24.
//

#ifndef BTREES_BTREE_ARRAY_FUNCTIONS_H
#define BTREES_BTREE_ARRAY_FUNCTIONS_H
#include "BTree_Array_Functions.h"

template <class T>
void split(T data1[], int& n1, T data2[], int& n2){
    int j=0;
    int start = n1 % 2 == 0 ? n1/2 : n1/2 + 1;
    for (int i=start; i<n1; i++){
        data2[j++] = data1[i];
        n2++;
    }
    n2 = n1/2;
    n1 = n1 - n1/2;
}

template <class T>
void insert_item(T data[], int idx, int& n, T entry){
    for (int i=n; i>idx; i--)
        data[i] = data[i-1];
    data[idx] = entry;
    n++;
}

template <class T>
void detach_item(T data[], int& n, T& entry){
    entry = data[n-1];
    n--;
}

#endif
