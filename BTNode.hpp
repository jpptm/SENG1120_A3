// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
// This script will contain the implementation of the template class BTNode
// This class will be used as data holders for our BSTree

// Implementation for BTNode.h is written here
#include "BTNode.h"

// Constructors
template <typename T>
BTNode<T>::BTNode()
{
    parent = NULL;
    left = NULL;
    right = NULL;
}


// This one uses arguments just to make code later on a bit cleaner
template <typename T>
BTNode<T>::BTNode(BTNode *parent_, BTNode *left_, BTNode *right_, T node_data_)
{
    parent = parent_;
    left = left_;
    right = right_;
    data = node_data_;
}


// Empty destructor
template <typename T>
BTNode<T>::~BTNode() {}


// Setters for next, previous and data entries
template <typename T>
void BTNode<T>::set_parent(BTNode *parent_)
{
    parent = parent_;
}


template <typename T>
void BTNode<T>::set_left(BTNode *left_)
{
    left = left_;
}


template <typename T>
void BTNode<T>::set_right(BTNode *right_)
{
    right = right_;
}


template <typename T>
void BTNode<T>::set_data(const T &node_data_)
{
    data = node_data_;
}


// Getters - use const when we can and non const when we must alter the state of the object
template <typename T>
BTNode<T> *BTNode<T>::get_parent() const
{
    return parent;
}


template <typename T>
BTNode<T> *BTNode<T>::get_left() const
{
    return left;
}


template <typename T>
BTNode<T> *BTNode<T>::get_right() const
{
    return right;
}


template <typename T>
T &BTNode<T>::get_data()
{
    return data;
}
