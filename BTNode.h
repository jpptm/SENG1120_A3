//
// Created by User on 16/05/2022.
//

#ifndef HASHPLUSTREE_BTNODE_H
#define HASHPLUSTREE_BTNODE_H
// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Macroguard


#include <cstdlib>

// This class will serve as data containers for our linked list
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

// Include to let compiler know implementation is in Node.hpp
#include "BTNode.hpp"

#endif //HASHPLUSTREE_BTNODE_H
