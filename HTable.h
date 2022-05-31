// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
// This script will contain the declaration for the template class HTable

// Initialise macro guard
#ifndef HTABLE_H
#define HTABLE_H

// Include Node and LinkedList files from assignment 2 - this will be for our buckets to avoid collisions
#include <ostream>
#include "LinkedList.h"

template <class T>
class HTable
{
public:
    // Initialise constructor and destructor
    HTable();
    ~HTable();

    // Declare functions to add items to our hash table
    void add(const T &item);
    void remove(const T &item);

    // --- --- --- Some specific methods that will cater directly to the Cities class --- --- --- //

    // Calculate total population within hash table
    int calculateTotalPop();
    // Calculate total population that is greater than the target in the hash table
    int calculatePopGreaterThan(int target);
    // Helper method to print the contents of the table
    std::ostream &print(std::ostream &out);

private:
    // Hash function that returns the location of the item within the table
    int hashfun(const T &value);
    // An array of linked lists with length 1000 - the linked list will serve as our bucket
    LinkedList<T> container[1000];
};

// Overload << to print the contents of the tree
template <typename T>
std::ostream &operator<<(std::ostream &out, const HTable<T> &);

// Let the compiler know that the implementation will be in the hpp file
#include "HTable.hpp"

#endif // HTABLE_H