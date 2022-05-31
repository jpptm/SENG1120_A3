// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
// This script contains the implementation for the template class BSTree

#include "BSTree.h"

// Constructor - set root to null and initialise size to 0
template <typename T>
BSTree<T>::BSTree()
{
    root = NULL;
    size = 0;
}


// Destroy every single node within tree using our private helper method
template <typename T>
BSTree<T>::~BSTree()
{
    destroyRecursively(root);
}


// Destroy nodes recursively - this is a private helper method that takes a node pointer and recursively traverses the tree and destroy Nodes along the way
template <typename T>
void BSTree<T>::destroyRecursively(const BTNode<T> *n)
{
    // Base case
    if (n == NULL)
    {
        return;
    }

    // Travel every node and destroy it till we reach nothingness
    destroyRecursively(n->get_left());
    destroyRecursively(n->get_right());

    // Delete data in node and decrement size
    delete n;
    size--;

}


// Add new node to tree
template <typename T>
void BSTree<T>::add(const T &item)
{
    // If tree is empty make a new node and set that to root then size++
    if (root == NULL)
    {
        BTNode<T>* new_node = new BTNode<T>(NULL, NULL, NULL, item);
        root = new_node;
        size++;
        return;
    }
    // If not then use recursion to add item to tree
    else
    {
        helpAdd(root, item);
    }
}


// Help add new node to tree
template <typename T>
BTNode<T>* BSTree<T>::helpAdd(BTNode<T> *n, const T &item)
{
    // If our item is smaller than the current node go left
    if (item < n->get_data())
    {
        // Check left node and if not empty
        if (n->get_left())
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

    // Do the same thing for the other case - if item is bigger than the current node then go right
    if (item > n->get_data())
    {
        // If right child is not NULL
        if (n->get_right())
        {
            n->set_right(helpAdd(n->get_right(), item));
        }
        // If it is null just set the new node to be the new right child
        else
        {
            n->set_right(new BTNode<T>(n, NULL, NULL, item));
            size++;
        }
    }

    // Return n pointer for current recursive call
    return n;
}


// Search for target node and remove it from tree
template <typename T>
void BSTree<T>::remove(const T &target)
{
    // Use helper method to do the recursion to delete the target node
    root = helpRemove(root, target);
}


// Recursive function to serve as helper method for remove()
template <typename T>
BTNode<T>* BSTree<T>::helpRemove(BTNode<T>*n, const T &target)
{
    // Base case
    if (n == NULL)
    {
        return n;
    }
    // If target is smaller than the current node go left
    if (target < n->get_data())
    {
        n->set_left(helpRemove(n->get_left(), target));
    }
    // If not then go right
    else if (target > n->get_data())
    {
        n->set_right((helpRemove(n->get_right(), target)));
    }
    // Reaching this means we hit our target node - now we have to figure out if it has 0, 1 or 2 children
    else
    {
        // If it's a leaf node
        if (n->get_left() == NULL && n->get_right() == NULL)
        {
            return NULL;
        }
        // If it has a right child
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
        // Find the inorder successor of the node then recursively go through it to replace it
        BTNode<T>* temp = findMin(n->get_right());
        // Replace the target node's value with the inorder successor's and delete the inorder successor
        n->set_data(temp->get_data());
        n->set_right(helpRemove(n->get_right(), temp->get_data()));
    }
    // Return pointer
    return n;
}


// Calculate the total population of all the nodes within the tree
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
    // Base case - if node is null then its population is 0
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
    // Use helper method to traverse the tree
    return traverseGetIfBigger(root, target);
}


// Get population data if population is bigger than target
template <typename T>
int BSTree<T>::traverseGetIfBigger(BTNode<T> *n, const int target) const
{
    // Base case
    if (n == NULL)
    {
        return 0;
    }

    // If node is not null or population of the node is > target then add its population to ans while travelling the whole tree
    else
    {
        // Initialise return value
        int ans = 0;

        // Go to left recursively
        ans += traverseGetIfBigger(n->get_left(), target);
        // If current node's value is greater than target increment its value to ans
        if (n->get_data().get_population() > target)
        {
            ans += n->get_data().get_population();
        }
        // Go to right recursively
        ans += traverseGetIfBigger(n->get_right(), target);

        return ans;
    }
}


// Return size of tree
template <typename T>
int BSTree<T>::get_size() const
{
    return size;
}


// Find the node with the smallest value from our starting node
template <typename T>
BTNode<T>* BSTree<T>::findMin(BTNode<T> *n) const
{
    // Just keep going left since we know that our tree will have its min value at the left most leaf from our starting node
    BTNode<T>* curr = n;
    while ((curr != NULL) && (curr->get_left() != NULL))
    {
        curr = curr->get_left();
    }

    return curr;
}


// Find target recursively
template <typename T>
BTNode<T>* BSTree<T>::find(BTNode<T>* n, T &target) const
{
    // Base case
    if ((n->get_data() == target) || (n == NULL))
    {
        return n;
    }
    // Go left or right based on the target's data
    else
    {
        if (target < n->get_data())
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


// Use helper method for printing the contents of the tree
template <typename T>
std::ostream& BSTree<T>::print(std::ostream& out) const
{
    return helpPrint(out, root);
}


// Make a helper method that uses an ostream to print our tree inorderly
template <typename T>
std::ostream& BSTree<T>::helpPrint(std::ostream &out, BTNode<T>* n) const
{
    // If node is not null get data and process it
    if (n != NULL)
    {
        helpPrint(out, n->get_left());
        out << "(" << n->get_data().get_name() << ", " << n->get_data().get_population() << ") ";
        helpPrint(out, n->get_right());
    }
    // Return out once the recursive process finishes
    return out;
}


// Operator overload for << to  show the contents of the tree inorderly
template<typename T>
std::ostream& operator <<(std::ostream& out, const BSTree<T>& obj)
{
  return obj.print(out);
}
