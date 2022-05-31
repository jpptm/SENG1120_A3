// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
// This script contains the declaration for members and non-members of the BSTree class


// Initialise macro guard
#ifndef BSTREE_H
#define BSTREE_H

#include "BTNode.h"
#include <ostream>

template <class T>
class BSTree
{
public:
    // Initialise constructor
    BSTree();

    // Initialise destructor - this should delete every single node within the tree
    ~BSTree();

    // Add item to tree
    void add(const T &item);

    // Remove item from tree
    void remove(const T &target);

    // Get size of tree
    int get_size() const;

    // --- --- --- Specific methods that cater to the City class directly --- --- --- //

    // This goes through the whole binary tree and finds the total number of population for the whole tree
    int calculateTotalPop() const;

    // This goes through the tree and if the data of the node is greater than the argument, it increments and returns that value
    int calculatePopGreaterThan(int) const;

    // For overloading << to print tree contents
    std::ostream& print(std::ostream& out) const;

private:
    // A binary search tree should have a root i.e., the origin node
    BTNode<T> *root;

    // Keep track of the size of the binary tree using a size member
    int size;

    // --- --- --- Some needed helper methods follow --- --- --- //

    // Helper for destructor
    void destroyRecursively(const BTNode<T> *node);

    // Helper for add
    BTNode<T>* helpAdd(BTNode<T>* n, const T &item);

    // Helpers for remove - need to find minimum node within tree if we are to remove a node with 2 children
    BTNode<T>* helpRemove(BTNode<T>*n, const T &target);

    // Find specific nodes - findMin finds the minimum node from a starting node and find just returns target once found
    BTNode<T>* findMin(BTNode<T> *n) const;
    BTNode<T>* find(BTNode<T>* n, T& target) const;

    // Helper methods for getting total population and population greater than target
    int traverseGetPop(BTNode<T>* n) const;
    int traverseGetIfBigger(BTNode<T>* n, int target) const;

    // Helper method for printing tree contents
    std::ostream& helpPrint(std::ostream& out, BTNode<T>* n) const;
};

// operator overload << printing the contents of the tree - RETURN OSTREAM
template <typename T>
std::ostream& operator <<(std::ostream&, const BSTree<T>&);

// Let the compiler know that the implementation is in BSTree.hpp
#include "BSTree.hpp"

#endif //BSTREE_H