// Initialise macroguard
#ifndef HASHPLUSTREE_BSTREE_H
#define HASHPLUSTREE_BSTREE_H

// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

#include "BTNode.h"
#include <iostream>

// TEMPORARY
#include "Cities.h"

template <class T>
class BSTree
{
public:
    // Initialise constructors
    BSTree();

    // Initialise destructor - this should delete every single node within the tree
    ~BSTree();

    // All relevant generic tree methods follow below
    // Add(city)
    void add(const T &item);

    // Remove(city)
    void remove(const T &target);

    // Get size of tree
    int count() const;

    // --- --- --- Specific methods that cater to the City class --- --- ---

    // This goes through the whole binary tree and finds the total number of population for the whole tree
    int calculateTotalPop() const;

    // This goes through the tree and if the data of the node is greater than the argument,
    // it increments and returns that value
    int calculatePopGreaterThan(int) const;

private:
    // A binary search tree should have a root i.e., the origin node
    BTNode<T> *root;

    // Keep track of the size of the binary tree using a size member
    int size;

    // Some needed helper methods follow

    // Helper for destructor
    void destroyRecursively(BTNode<T> *node);
    // Helper for add
    BTNode<T>* helpAdd(BTNode<T>* n, const T &item);
    // Helpers for remove - need to find minimum node within tree if we are to remove a node with 2 children
    BTNode<T>* helpRemove(BTNode<T>*n, const T &target);
    BTNode<T>* findMin(BTNode<T> *n) const;
    BTNode<T>* find(BTNode<T>* n, T& target) const;

};

// operator overload << printing the contents of the tree - RETURN OSTREAM
std::ostream& operator <<(std::ostream&, const BSTree<Cities>&);

// Let the compiler know that the implementation is in BSTree.hpp
#include "BSTree.hpp"

#endif // HASHPLUSTREE_BSTREE_H