// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Macroguard
#ifndef NODE_H
#define NODE_H

#include <cstdlib>

// This class will serve as data containers for our linked list
template <class T>
class Node
{
public:
    // Initialising constructors
    Node();
    Node(Node *next, Node *previous, T data);
    // Initialise empty destructor
    ~Node();

    // Initialise getters and setters
    void set_next(Node *next_);
    void set_previous(Node *previous_);
    void set_data(const T &node_data_);

    Node *get_next() const;
    Node *get_previous() const;
    T &get_data();

    // Declare private member variables
private:
    Node *next;
    Node *previous;
    T data;
};

// Include to let compiler know implementation is in Node.hpp
#include "Node.hpp"

#endif // NODE_H
