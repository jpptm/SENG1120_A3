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
void BSTree<T>::add(const T item)
{
    // If tree is empty make a new node and set that to root then size++
    if(size == 0)
    {
        BTNode<T>* new_node = new BTNode<T>(NULL, NULL, NULL, item);
        root = new_node;
    }
    else
    {
        helpAdd(root, item);
    }
    size++;
}

// Search for target node and remove it from tree
template <typename T>
T BSTree<T>::remove(const T target)
{
    T payload;
    if(size == 0)
    {
        return payload;
    }

    if(size == 1)
    {
        payload = root->get_data();
        delete root;
        root = NULL;
    }

    // If our tree has more than 2 nodes in it
    else
    {
        // Find our target within the tree and remove it
    }

    size--;
    return payload;
}

// Find total population of tree
template <typename T>
int BSTree<T>::calculateTotalPop() const
{
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
void BSTree<T>::destroyRecursively(BTNode<T> *node)
{
    if (node)
    {
        destroyRecursively(node->get_left());
        destroyRecursively(node->get_right());
        delete node;
    }
}

// Help add new node to tree
template <typename T>
void BSTree<T>::helpAdd(BTNode<T> *n, T item)
{
    // Replace duplicate if it exists
    if(item == n->get_data())
    {
        n->set_data(item);
    }
    // Item goes to right if it is bigger than current else it goes left
    else if(item > n->get_data())
    {
        if(n->get_right() == NULL)
        {
            BTNode<T> *newNode = new BTNode<T>(n, NULL, NULL, item);
            n->set_right(newNode);
        }
        else
        {
            helpAdd(n->get_right(), item);
        }
    }
    // Left side
    else
    {
        if(n->get_left() == NULL)
        {
            BTNode<T> *newNode = new BTNode<T>(n, NULL, NULL, item);
            n->set_left(newNode);
        }
        else
        {
            helpAdd(n->get_left(), item);
        }
    }
}

// Find the node with the least value, so we can use that to balance our tree if our target has 2 children
template <typename T>
T BSTree<T>::helpRemove(BTNode<T>*n, T target)
{
    T payload;
    // Base case - if our current node is the target then delete that node
    if(n->get_data() == target)
    {
        // If node is a leaf node just delete it
        if((n->get_left() == NULL) && (n->get_right()==NULL))
        {
            // Get payload data ready
            payload = n->get_data();
            // We have to make sure that the parent's pointers are correct as well
            BTNode<T>* nParent = n->get_parent();

            // Account for segfaults
            if(nParent->get_left() != NULL)
            {
                // If below is true then this means that our target is the left child of its parent
                if(nParent->get_left()->get_data() == n->get_data())
                {
                    delete n;
                    nParent->set_left(NULL);
                }
                    // If above is false then our target node has to be the right child of its parent
                else
                {
                    delete n;
                    nParent->set_right(NULL);

                }
            }
            // If left is NULL then our target has to be the right child of its node
            else
            {
                delete n;
                nParent->set_right(NULL);
            }
        }
        // Account for non-leaf nodes - if the target has at least 1 children then we have to rebalance the tree somehow
        else
        {
            // ........
        }
    }



    return payload;
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
BTNode<T>* BSTree<T>::find(BTNode<T>* n, T target) const
{
    // Find target using inorder traversal
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
    // If we don't find anything, return NULL - this means that the target does not exist
}