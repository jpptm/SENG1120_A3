// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
// This script will contain the implementation for the template class HTable

#include "HTable.h"
#include <string>

// Declare TABLE_SIZE to be const 1000 as per the assignment's requirements
#define TABLE_SIZE 1000

// Define empty constructor - linked list is already initialised so this is all good
template <typename T>
HTable<T>::HTable()
{
}


// Empty destructor - let the LinkedList's destructor do the clean-up
template <typename T>
HTable<T>::~HTable()
{
}


// Hash function to derive position of the item within the table - given in the spec, I just had to copy and paste it
template <typename value_type>
int HTable<value_type>::hashfun(const value_type &value)
{
    int position = 0;
    std::string temp = value.get_name();

    for (int i = 0; i < (int)temp.length(); i++)
    {
        position += (i + 1) * (i + 1) * temp.at(i);
    }
    return position % TABLE_SIZE;
}


// Add item to the hash table
template <typename T>
void HTable<T>::add(const T &item)
{
    // Get the corresponding key for the argument then add to the tail of the LinkedList at container[key]
    const int key = hashfun(item);
    container[key].add_to_tail(item);
}


// Remove item from hash table
template <typename T>
void HTable<T>::remove(const T &item)
{
    // Get location of target to be removed
    const int key = hashfun(item);

    // Traverse the linked list at the location we want
    for (int i = 0; i < container[key].size(); i++)
    {
        if (container[key].get_from_current() == item)
        {
            // Item found - remove it then get out
            container[key].remove_from_current();

            // Make sure to reset current pointer, so we don't get any weird errors
            container[key].start();
            break;
        }
        // If we don't find the target then just move on to the next element of the linked list
        else
        {
            container[key].forward();
        }
    }
    // Reset current pointer after using it to make sure we don't get any seg faults
    container[key].start();
}


// Calculate the total population of all the nodes within the hash table
template <typename T>
int HTable<T>::calculateTotalPop()
{
    // Initialise return value
    int totalPop = 0;

    // Run through the whole table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // Get all the data within the list for the current iteration
        for (int j = 0; j < container[i].size(); j++)
        {
            totalPop += container[i].get_from_current().get_population();
            container[i].forward();
        }
        // Reset current pointer to head
        container[i].start();
    }
    // Return total population
    return totalPop;
}


// Calculate the population of cities with population > than the argument target
template <typename T>
int HTable<T>::calculatePopGreaterThan(const int target)
{
    // Initialise return value
    int targetPop = 0;

    // Go through the whole table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // Go through the list at iteration i
        for (int j = 0; j < container[i].size(); j++)
        {
            // If the current node's population is greater than get then increment its population to our return value
            if (container[i].get_from_current().get_population() > target)
            {
                targetPop += container[i].get_from_current().get_population();
            }
            // Go to the next node
            container[i].forward();
        }
        // Make sure to reset the current pointer to the beginning of the list to avoid seg faults
        container[i].start();
    }
    return targetPop;
}


// Helper method to print the contents of the tree
template <typename T>
std::ostream &HTable<T>::print(std::ostream &out)
{
    // Traverse the whole table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // Traverse the whole container
        for (int j = 0; j < container[i].size(); j++)
        {
            // Add contents to the ostream reference in the format of (city_name, city_population)
            out << "(" << container[i].get_from_current().get_name() << ", " << container[i].get_from_current().get_population() << ") ";
            // Move to the next element of the linked list
            container[i].forward();
        }
        // Reset current pointer to head to make sure we don't get any segfaults
        container[i].start();
    }
    return out;
}


// Operator overload for << to print the contents of the table
template <typename T>
std::ostream &operator<<(std::ostream &out, HTable<T> &table)
{
    return table.print(out);
}