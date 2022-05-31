// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

#include "HTable.h"
#define TABLE_SIZE 1000;


template <typename T>
HTable<T>::HTable()
{
}


template <typename T>
HTable<T>::~HTable()
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < container[i].size(); j++)
        {
            container[i].remove_from_current();
            container[i].forward();
        }
        container[i].start();
    }
}


template <typename value_type>
int HTable<value_type>::hashfun(const value_type& value) {
    int position = 0;
    string temp = value.get_name();

    for (int i=0; i<(int)temp.length(); i++)
    {
        position += (i+1) * (i+1) * temp.at(i);
    }
    return position % TABLE_SIZE;
}


template <typename T>
void HTable<T>::add(const T& item)
{
    // Get the corresponding key for the argument then add to the tail of the LinkedList at container[key]
    int key = hashfun(item);
    container[key].add_to_tail(item);
}


template <typename T>
void HTable<T>::remove(const T& item)
{
    // Get key and location
    const int key = hashfun(item);

    // Traverse the linked list at the location we want
    for (int i = 0; i < container[key].size(); i++)
    {
        if(container[key].get_from_current() == item)
        {
            // Item found - remove it then get out
            container[key].remove_from_current();

            // Make sure to reset current pointer so we don't get any weird errors
            container[key].start();
            break;
        }
        else
        {
            container[key].forward();
        }
    }
    // Reset current pointer after using it
    container[key].start();
}


template <typename T>
int HTable<T>::calculateTotalPop()
{
    int totalPop = 0;

    // Run through the whole table
    for(int i = 0 ;i < 1000; i++)
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

    return totalPop;
}


template <typename T>
int HTable<T>::calculatePopGreaterThan(const int target)
{
    int targetPop = 0;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < container[i].size(); j++)
        {
            if (container[i].get_from_current().get_population() > target)
            {
                targetPop += container[i].get_from_current().get_population();
            }
            container[i].forward();
        }
        container[i].start();
    }
    return targetPop;
}


template <typename T>
std::ostream& HTable<T>::print(std::ostream& out)
{
    for (int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < container[i].size(); j++)
        {
            out << "(" << container[i].get_from_current().get_name() << ", " << container[i].get_from_current().get_population() << ") ";
            container[i].forward();
        }
        // Reset current pointer to head;
        container[i].start();
    }
    return out;
}


template <typename T>
std::ostream& operator <<(std::ostream& out, HTable<T>& table)
{
    return table.print(out);
}