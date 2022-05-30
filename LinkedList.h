// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Macroguard
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

// Linked list class to contain all nodes with needed data
template <class T>
class LinkedList
{
public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Setters
    void add_to_head(const T &node_data);
    void add_to_tail(const T &node_data);
    void add_to_current(const T &node_data);

    // Getters and mutators
    T &get_from_head() const;
    T &get_from_tail() const;
    T &get_from_current() const;

    T remove_from_head();
    T remove_from_tail();
    T remove_from_current();

    // Current manipulators
    void start();
    void end();
    void forward();
    void back();

    // Statistics
    int size() const;

private:
    // Include current, head and tail for LL
    Node<T> *current;
    Node<T> *head;
    Node<T> *tail;

    // Number of nodes within the list
    int list_length;
};

// Let compiler know implementation of LinkedList is in the .hpp file
#include "LinkedList.hpp"

#endif // LINKED_LIST_H