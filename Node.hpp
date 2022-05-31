// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
// This class will be used as data holders for a linked list
// Implementation for Node.h is written here

#include "Node.h"


// Constructors
template <typename T>
Node<T>::Node()
{
    next = NULL;
    previous = NULL;
}


// This one uses arguments just to make code later on a bit cleaner
template <typename T>
Node<T>::Node(Node *next_node, Node *previous_node, T node_data_)
{
    next = next_node;
    previous = previous_node;
    data = node_data_;
}


// Empty destructor
template <typename T>
Node<T>::~Node() {}


// Setters for next, previous and data entries
template <typename T>
void Node<T>::set_next(Node *next_)
{
    next = next_;
}


template <typename T>
void Node<T>::set_previous(Node *previous_)
{
    previous = previous_;
}


template <typename T>
void Node<T>::set_data(const T &node_data_)
{
    data = node_data_;
}


// Getters - use const when we can and non const when we must alter the state of the object
template <typename T>
Node<T> *Node<T>::get_next() const
{
    return next;
}


template <typename T>
Node<T> *Node<T>::get_previous() const
{
    return previous;
}


template <typename T>
T &Node<T>::get_data()
{
    return data;
}
