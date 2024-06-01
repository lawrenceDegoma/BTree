//
// Created by Lawrence Degoma on 5/30/24.
//

#ifndef BTREES_BTREE_CPP
#define BTREES_BTREE_CPP
#include "BTree.h"

// Constructor
template <typename T>
BTree<T>::BTree(int min_degree) : root(nullptr), t(min_degree){}

template <typename T>
BTree<T>::~BTree(){
    // To be continued...
}

// Insert new key
template <typename T>
void BTree<T>::insert(const T& key){
    // If no root exists, create one silly
    if (root == nullptr){
        root = new Node<T>(t, true);
        root->keys[0] = key;
        root->n = 1;
    }
    else{
        // Check if node violates the rule
        if (root->n == 2 * t - 1){
            Node<T>* s = new Node<T>(t, false);
            s->children[0] = root;
            split_child(s, 0);
            insert_non_full(s, key);
            root = s;
        }
        // Otherwise insert as usual
        else{
            insert_non_full(root, key);
        }
    }
}

template <typename T>
void BTree<T>::insert_non_full(Node<T>* node, const T& key){
    int i = node->n - 1;
    // if key is a leaf, insert it into the node
    // while loop finds the correct index to place the key
    // and shifts everything to the right accordingly
    // update num of keys
    if (node->is_leaf){
        while (i>=0 && node->keys[i]>key){
            node->keys[i+1] = node->keys[i];
            i--;
        }
        node->keys[i+1] = key;
        node->n++;
    }

    // if key is not a leaf, find the right child to put the key into
    // while loop finds the right child
    else{
        while (i>=0 && node->keys[i]>key){
            i--;
        }
        // If child is full, split the child in half
        if (node->children[i+1]->n == 2 * t-1){
            split_child(node, i+1);
            if (node->keys[i+1] < key){
                i++;
            }
        }

        // big dog on campus moment
        insert_non_full(node->children[i+1], key);
    }
}


// Params: parent node and index
template <typename T>
void BTree<T>::split_child(Node<T>* node, int i){
    // Child we are splitting
    Node<T>* y = node->children[i];

    // Create new node to store the spills of the child (second half)
    Node<T>* z = new Node<T>(y->degree, y->is_leaf);
    z->n = t-1;

    // Copy said spills into z
    for (int j=0; j<t-1; j++){
        z->keys[j] = y->keys[j+t];
    }

    // Move second half of y's children to z
    if (!y->is_leaf){
        for (int j=0; j<t; j++){
            z->children[j] = y->children[j+t];
        }
    }

    // Update number of keys
    y->n = t-1;

    for (int j=node->n; j>=i+1; j--){
        node->children[j+1] = node->children[j];
    }

    node->children[i+1] = z;
    for (int j=node->n-1; j>=i; j--){
        node->keys[j+1] = node->keys[j];
    }

    node->keys[i] = y->keys[t-1];
    node->n++;
}

template <typename T>
void BTree<T>::print(std::ostream &out) const {
    print(root, out, 0);
}

template <typename T>
void BTree<T>::print(Node<T>* node, std::ostream &out, int depth) const {
    if (node != nullptr) {
        if (node->n > 0 && node->children[node->n] != nullptr)
            print(node->children[node->n], out, depth + 1);
        for (int i = node->n - 1; i >= 0; i--) {
            for (int j = 0; j < depth; j++)
                out << "\t";
            out << node->keys[i] << "\n";
            if (node->children[i] != nullptr)
                print(node->children[i], out, depth + 1);
        }
    }
}

#endif
