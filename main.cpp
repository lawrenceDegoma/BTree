#include <iostream>
#include "BTree.h"

int main() {
    // Minimum degree is the value that BTree takes
    // Maximum degree = 2(Minimum degree) - 1
    BTree<int> btree(2);

    btree.insert(15);
    btree.insert(5);
    btree.insert(20);
    btree.insert(25);
    btree.insert(10);
    btree.insert(30);
    btree.insert(35);
    btree.insert(40);
    btree.insert(45);
    btree.insert(50);
    btree.insert(55);
    btree.insert(60);
    btree.insert(65);
    btree.insert(70);
    btree.insert(75);


    std::cout << "BTree:\n";
    btree.print();

    return 0;
}
