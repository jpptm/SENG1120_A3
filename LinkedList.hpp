// Implementation for LinkedList.h is here
#include "LinkedList.h"

// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// LinkedList constructor - initialise all pointers to null
template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    current = NULL;
    tail = NULL;
    list_length = 0;
}

// LinkedList destructor - destroy all nodes within LL
template <typename T>
LinkedList<T>::~LinkedList()
{
    // If our LinkedList is not empty go through every single node and delete it
    current = head;
    Node<T> *temp = current;
    while (current != NULL)
    {
        temp = current->get_next();
        delete current;
        current = temp;
    }
}

// Add new node as new head of LL
template <typename T>
void LinkedList<T>::add_to_head(const T &node_data)
{
    // Initialise new node in the heap and set node_data as its data
    Node<T> *new_node = new Node<T>(head, NULL, node_data);

    // Make new node as new head and update all relevant pointers - if we have a head we can just do this
    if (head != NULL)
    {
        // Set previous and reset pointers
        head->set_previous(new_node);

        head = new_node;
        current = head;
    }

    // If list is empty just set that node as head, current and tail
    else
    {
        head = new_node;
        current = new_node;
        tail = new_node;
    }

    // Increment list length
    list_length++;
}

// Add new node to the right of the current node - only use if list_length > 2 and current = head
template <typename T>
void LinkedList<T>::add_to_current(const T &node_data)
{
    // Initialise new node in the heap and set node_data as its data
    Node<T> *new_node = new Node<T>();
    new_node->set_data(node_data);

    // If list is not empty
    if (list_length != 0)
    {
        // New node's next must be current's next and previous must be current
        Node<T> *current_next = current->get_next();

        current->set_next(new_node);
        new_node->set_previous(current);

        new_node->set_next(current_next);
        current_next->set_previous(new_node);

        current = new_node;
    }

    // If list is empty just set that node as head, current and tail
    else
    {
        head = new_node;
        current = new_node;
        tail = new_node;
    }
    // Increment list length
    list_length++;
}

template <typename T>
void LinkedList<T>::add_to_tail(const T &node_data)
{
    // Initialise new node in the heap and set node_data as its data
    Node<T> *new_node = new Node<T>();
    new_node->set_data(node_data);

    if (tail != NULL)
    {
        // Set new node as new tail and update pointers
        tail->set_next(new_node);
        new_node->set_previous(tail);

        new_node->set_next(NULL);

        tail = new_node;
    }

    // If list is empty just set that node as head, current and tail
    else
    {
        head = new_node;
        current = new_node;
        tail = new_node;
    }

    // Increment list length
    list_length++;
}

// We make sure that any functions that shouldn't alter the state of the class won't
// Get head node of LL
template <typename T>
T &LinkedList<T>::get_from_head() const
{
    return head->get_data();
}

// Get current node of LL
template <typename T>
T &LinkedList<T>::get_from_current() const
{
    return current->get_data();
}

// Get tail node of LL
template <typename T>
T &LinkedList<T>::get_from_tail() const
{
    return tail->get_data();
}

// Remove head node
template <typename T>
T LinkedList<T>::remove_from_head()
{
    T payload;

    // If LL is not empty
    if (head)
    {
        // Get data within node before deletion and return it
        payload = head->get_data();

        // Set head's next as new head, delete head, make sure new head points to null and reset current to head
        if (head->get_next() != NULL)
        {
            Node<T> *new_head = head->get_next();
            delete head;
            head = new_head;
            head->set_previous(NULL);

            current = head;
        }

        // If next is NULL that means its the only node in the LL - make sure to reset pointers to avoid segfaults
        else
        {
            delete head;
            head = NULL;
            current = NULL;
            tail = NULL;
        }

        // Decrement list length
        list_length--;

        return payload;
    }

    else
    {
        return payload;
    }
}

// Remove current node - must only use this function if LL has length > 2 - use only if absolutely needed
template <typename T>
T LinkedList<T>::remove_from_current()
{
    T payload;

    // Tail case - we're deleting tail
    if (current->get_next() == NULL)
    {
        Node<T>* current_previous = current -> get_previous();
        payload = current -> get_data();
        delete current;
        current = current_previous;

        if (current != NULL)
        {
            current->set_next(NULL);
        }

        tail = current;
    }
    // Head case - we're deleting head
    else if (current->get_previous() == NULL)
    {
        Node<T>* current_next = current -> get_next();
        payload = current -> get_data();
        delete current;
        current = current_next;

        if(current != NULL)
        {
            current->set_previous(NULL);
        }

        head = current;
    }
    // Internal node case
    else
    {
        // Get data within node before deletion and return it
        payload = current->get_data();

        // Get current's next and previous nodes and link them together
        Node<T> *current_next = current->get_next();
        Node<T> *current_previous = current->get_previous();

        current_previous->set_next(current_next);
        current_next->set_previous(current_previous);

        // Delete current, set current_previous as new current, return data of deleted node
        delete current;
        current = current_previous;
    }

    // Decrement list length
    list_length--;
    return payload;
}

// Remove tail node
template <typename T>
T LinkedList<T>::remove_from_tail()
{
    T payload;

    // If LL is not empty
    if (list_length != 0)
    {
        // Get tail data before deletion and return it afterwards
        payload = tail->get_data();

        if (tail->get_previous() != NULL)
        {
            // Get tail's previous, set that as new tail, delete current tail, make sure new tail points to NULL, return data
            Node<T> *new_tail = tail->get_previous();

            delete tail;
            tail = new_tail;
            tail->set_next(NULL);

            // Decrement list length
            list_length--;
        }

        // If below is the case then tail is the only LL within the list
        else
        {
            delete tail;
            list_length--;
        }

        return payload;
    }

    else
    {
        return payload;
    }
}

// Set current back to head
template <typename T>
void LinkedList<T>::start()
{
    current = head;
}

// Set current to tail
template <typename T>
void LinkedList<T>::end()
{
    current = tail;
}

// Move current one node forward
template <typename T>
void LinkedList<T>::forward()
{
    if(current != NULL)
    {
        current = current->get_next();
    }
}

// Move current one node back
template <typename T>
void LinkedList<T>::back()
{
    current = current->get_previous();
}

// Get list's size by returning list_length
template <typename T>
int LinkedList<T>::size() const
{
    return list_length;
}