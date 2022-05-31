// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
// This script will contain the declarations for the template class BTNode
// BTNode will serve as a data container to be used by a binary search tree

// Initialise macro guard
#ifndef BTNODE_H
#define BTNODE_H

#include <cstdlib>

// This class will serve as data containers for our BSTree
template<class T>
class BTNode {
public:
    // Initialising constructors
    BTNode();
    BTNode(BTNode *parent_, BTNode *left_, BTNode *right_, T data);

    // Initialise empty destructor
    ~BTNode();

    // Initialise getters and setters
    void set_left(BTNode *left_);
    void set_right(BTNode *right_);
    void set_parent(BTNode *parent_);
    void set_data(const T &node_data_);

    BTNode *get_left() const;
    BTNode *get_right() const;
    BTNode *get_parent() const;
    T &get_data();

    // Declare private member variables
private:
    BTNode *left;
    BTNode *right;
    BTNode *parent;
    T data;
};

// Include to let compiler know implementation is in BTNode.hpp
#include "BTNode.hpp"

#endif // BTNODE_H
