// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

#include "BSTree.h"

// Constructor
template <typename T>
BSTree<T>::BSTree()
{
    root = NULL;
}


template <typename T>
BSTree<T>::~BSTree()
{
    // Destroy every single node within tree using our private helper method
    destroyRecursively(root);
}


// Add new node to tree
template <typename T>
void BSTree<T>::add(const T &item)
{
    // If tree is empty make a new node and set that to root then size++
    if(root == NULL)
    {
        BTNode<T>* new_node = new BTNode<T>(NULL, NULL, NULL, item);
        root = new_node;
        size++;
        return;
    }
    else
    {
        helpAdd(root, item);
    }
}


// Search for target node and remove it from tree - doesn't really make sense if we try to return the item we are removing
// as we already have to know what we want to delete in the first place
template <typename T>
void BSTree<T>::remove(const T &target)
{
    // Use helper method to do the recursion to delete the target node -- IN CAREFUL DEVELOPMENT
    BTNode<T> *start = root;
    helpRemove(start, target);
}


// Find total population of tree
template <typename T>
int BSTree<T>::calculateTotalPop() const
{
    // Traverse the whole tree; while traversing get the population data of each object then move recursively
    BTNode<T> *start = root;


    return 0;
}


// Find total population of cities if that city's population is greater than the argument
template <typename T>
int BSTree<T>::calculatePopGreaterThan(int target) const
{
    return 0;
}


// Return size of tree
template <typename T>
int BSTree<T>::count() const
{
    return size;
}


// Overload << to print tree of cities
std::ostream& operator <<(std::ostream& out, const BSTree<Cities> &c)
{
    return out;
}

// --- --- --- --- Private helper methods follow --- --- --- ---

// Destroy nodes recursively - this is a private helper method that takes a node pointer and recursively traverses
// the tree and destroy Nodes along the way
template <typename T>
void BSTree<T>::destroyRecursively(BTNode<T> *n)
{
    if(n == NULL)
    {
        return;
    }

    destroyRecursively(n->get_left());
    destroyRecursively(n->get_right());

    delete n;
    size--;

}


// Help add new node to tree
template <typename T>
BTNode<T>* BSTree<T>::helpAdd(BTNode<T> *n, const T &item)
{
    // Item goes to right if it is bigger than current else it goes left
    if(item > n->get_data())
    {
        if(n->get_right() == NULL)
        {
            BTNode<T> *newNode = new BTNode<T>(n, NULL, NULL, item);
            n->set_right(newNode);
            size++;
        }
        else
        {
            n->set_right(helpAdd(n->get_right(), item));
        }
    }

    // Left side
    if(item < n->get_data())
    {
        if(n->get_left() == NULL)
        {
            BTNode<T> *newNode = new BTNode<T>(n, NULL, NULL, item);
            n->set_left(newNode);
            size++;
        }
        else
        {
            n->set_left(helpAdd(n->get_left(), item));
        }
    }
    return n;
}


// Find the node with the least value, so we can use that to balance our tree if our target has 2 children
template <typename T>
BTNode<T>* BSTree<T>::helpRemove(BTNode<T>*n, const T &target)
{
    // Put this here so it doesnt die on us prematurely
    BTNode<T>* susp;
    // Base
    if(n == NULL)
    {
        return n;
    }

    // If target is bigger than our current node go right as our target will be in one of the subtrees to the right of our current node
    if(target > n->get_data())
    {
        n->set_right(helpRemove(n->get_right(), target));
        if(n->get_right())
        {
            n->get_right()->set_parent(n);
        }
    }

    // If target is smaller than current then go left
    else if(target < n->get_data())
    {
        n->set_left(helpRemove(n->get_left(), target));
        if(n->get_left())
        {
            n->get_left()->set_parent(n);
        }
    }

    // Reaching this block means that we have reached our target node - now we just gotta check the children of the node
    else
    {
        // Account for 0, 1 or 2 children for node

        // For 2 children
        if(n->get_left() != NULL && n->get_right() != NULL)
        {
            // Find min node to the right of our node i.e., inorder successor
            BTNode<T>* minToRight = findMin(n->get_right());

            // Replace current node's data with data of our min value
            n->set_data(minToRight->get_data());

            // Rebalance tree
            n->set_right(helpRemove(n->get_right(), n->get_data()));
        }

        // If it enters this block then its either a leaf node or a node with 1 child
        else
        {
            susp = n;

            // Check right - if right is null then our node has a left child
            if(n->get_right() == NULL)
            {
                n = n->get_left();
            }
            // If above is false then we have a node that has a right child
            else if(n->get_left() == NULL)
            {
                n = n->get_right();
            }
            // If none is true then it is a leaf node; we can just delete it
            delete susp;
            size--;
        }
    }

    // Check n - if n is null return n
    if(!n)
    {
        return n;
    }
    return n;
}

template <typename T>
BTNode<T>* BSTree<T>::findMin(BTNode<T> *n) const
{
    // Just keep going left since we know that our tree will have its min value at the left most leaf from our
    // starting node
    BTNode<T>* curr = n;
    while(curr && curr->get_left() != NULL)
    {
        curr = curr->get_left();
    }

    return curr;
}

template <typename T>
BTNode<T>* BSTree<T>::find(BTNode<T>* n, T &target) const
{
    // Find target
    if((n->get_data() == target) || (n == NULL))
    {
        return n;
    }
    else
    {
        if(target < n->get_data())
        {
            find(n->get_left(), target);
        }
        else
        {
            find(n->get_right(), target);
        }
    }
    // If we don't find anything it will return NULL - this means that the target does not exist
}

