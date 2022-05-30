// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Initialise macroguard
#ifndef HTABLE_H
#define HTABLE_H

// Include Node and LinkedList files from assignment 2 - this will be for our buckets
#include "LinkedList.h"
#include "Cities.h"

template <class T>
class HTable
{
public:

    HTable();
    ~HTable();

    void add(const T& item);
    void remove(const T& item);

    int calculateTotalPop();
    int calculatePopGreaterThan(const int target);

    std::ostream& print(std::ostream& out);

private:
    int hashfun(const T& value);
    LinkedList<T> container [1000];
};

template <typename T>
std::ostream& operator <<(std::ostream& out, const HTable<T>&);

#include "HTable.hpp"
#endif // HTABLE_H