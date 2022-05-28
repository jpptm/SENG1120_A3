// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

#include "BSTree.h"
#include <sstream>

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


// Help add new node to tree
template <typename T>
BTNode<T>* BSTree<T>::helpAdd(BTNode<T> *n, const T &item)
{
    if (item < n->get_data())
    {
        // Check left node and if not empty
        if(n->get_left())
        {
            // Set left node
            n->set_left(helpAdd(n->get_left(), item));
        }
            // Else add a new node
        else
        {
            // Remember to set n as parent of new node
            n->set_left(new BTNode<T>(n, NULL, NULL, item));
            size++;
        }
    }

    // Do the same thing for the other case
    if (item > n->get_data())
    {
        if(n->get_right())
        {
            n->set_right(helpAdd(n->get_right(), item));
        }
        else
        {
            n->set_right(new BTNode<T>(n, NULL, NULL, item));
            size++;
        }
    }

    return n;
}


// Search for target node and remove it from tree - doesn't really make sense if we try to return the item we are removing
// as we already have to know what we want to delete in the first place
template <typename T>
void BSTree<T>::remove(const T &target)
{
    // Use helper method to do the recursion to delete the target node -- IN CAREFUL DEVELOPMENT
    root = helpRemove(root, target);
}


// Find the node with the least value, so we can use that to balance our tree if our target has 2 children
template <typename T>
BTNode<T>* BSTree<T>::helpRemove(BTNode<T>*n, const T &target)
{
    // Base
    if (n == NULL)
    {
        return n;
    }

    if (target < n->get_data())
    {
        n->set_left(helpRemove(n->get_left(), target));
    }

    else if (target > n->get_data())
    {
        n->set_right((helpRemove(n->get_right(), target)));
    }

    else
    {
        // If it's a leaf node
        if (n->get_left() == NULL && n->get_right() == NULL)
        {
            return NULL;
        }

            // If has a right child
        else if (n->get_left() == NULL)
        {
            BTNode<T>* temp = n->get_right();
            delete n;
            size--;
            return temp;
        }

            // If it has a left child
        else if (n->get_right() == NULL)
        {
            BTNode<T>* temp = n->get_left();
            delete n;
            size--;
            return temp;
        }

        // Getting through here means we're dealing with a node with 2 children
        BTNode<T>* temp = findMin(n->get_right());
        n->set_data(temp->get_data());
        n->set_right(helpRemove(n->get_right(), temp->get_data()));
    }

    return n;
}


// Find total population of tree - could be int but I just like doubles better
template <typename T>
int BSTree<T>::calculateTotalPop() const
{
    // Traverse the whole tree; while traversing get the population data of each object then move recursively
    return traverseGetPop(root);
}


// Helper function for getting total population of Cities within BT - Will only work with instances of the class City
template<typename T>
int BSTree<T>::traverseGetPop(BTNode<T> *n) const
{
    // Base
    if (n == NULL)
    {
        return 0;
    }
    // Traverse whole tree and get pop for every node within
    else
    {
        return n->get_data().get_population() + traverseGetPop(n->get_left()) + traverseGetPop(n->get_right());
    }
}


// Find total population of cities if that city's population is greater than the argument
template <typename T>
int BSTree<T>::calculatePopGreaterThan(const int target) const
{
    return traverseGetIfBigger(root, target);
}


// Get population data if pop is bigger than target
template <typename T>
int BSTree<T>::traverseGetIfBigger(BTNode<T> *n, const int target) const
{
    // If node is not null or population of the node is > target add that while travelling the whole tree
    if (n == NULL)
    {
        return 0;
    }

    else
    {
        int ans = 0;

        ans += traverseGetIfBigger(n->get_left(), target);
        if (n->get_data().get_population() > target)
        {
            ans += n->get_data().get_population();
        }
        ans += traverseGetIfBigger(n->get_right(), target);

        return ans;
    }
}


// Return size of tree
template <typename T>
int BSTree<T>::count() const
{
    return size;
}


// --- --- --- --- Private helper methods follow --- --- --- ---
template <typename T>
BTNode<T>* BSTree<T>::findMin(BTNode<T> *n) const
{
    // Just keep going left since we know that our tree will have its min value at the left most leaf from our starting node
    BTNode<T>* curr = n;
    while((curr != NULL) && (curr->get_left() != NULL))
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

template <typename T>
std::ostream& BSTree<T>::print(std::ostream& out)
{
    return helpPrint(out, root);
}


// Use an ostream to print our tree inorderly
template <typename T>
std::ostream& BSTree<T>::helpPrint(std::ostream &out, BTNode<T>* n)
{
    // If node is not null get data
    if (n!=NULL)
    {
        helpPrint(out, n->get_left());
        out << "(" << n->get_data().get_name() << ", " << n->get_data().get_population() << ") ";
        helpPrint(out, n->get_right());
    }
    return out;
}

std::ostream& operator <<(std::ostream& out, BSTree<Cities>& obj)
{
  return obj.print(out);
}