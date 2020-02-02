/*
 *  Yet another AVL tree edition
 * 
 *  Contributors:
 *      Aaron S. Crandall <acrandal@wsu.edu> - 2018
 * 
 */

#ifndef __AVLTree_H
#define __AVLTree_H

#include <ostream>
#include <algorithm>     // Includes a max(a,b) function
#include <exception>

#include "AVLNode.h"

using namespace std;

// AVLTree class
// ******************PUBLIC OPERATIONS*********************
// bool empty( )          --> Test for empty tree
// int size( )            --> Quantity of elements in tree
// int height( )          --> Height of the tree (nullptr == -1)
// void add( x )          --> Insert new value x
// void remove( x )       --> Remove node with value x
// void clear ( )         --> Removes all elements from tree
// bool contains( x )     --> Return true if x is present
// T findMin( )           --> Return smallest item value
// T findMax( )           --> Return largest item value
// void printPreOrder( )  --> Print tree in pre order to an ostream
// void ~AVLTree( )       --> Big Five Destructor
// AVLTree( )             --> Basic constructor


template <typename T>
class AVLTree
{
private:
    AVLNode<T> * _root;

public:
    AVLTree() : _root(nullptr) {}    // initializes root to nullptr

    /* Returns true if the tree is empty */
    bool empty() {
        if(_root == nullptr) return true;
        return false;
        // Properly return t/f if the tree is empty or not
    }

    void add(const T & newVal) {
        // TODO: implement adding a value to the tree
        add(newVal, _root);

    }

    void remove(const T & remVal) {
        // TODO: Implemente properly removing a node and rebalancing the tree
        remove(remVal, _root);
    }

    void clear() {
        deleteAllFrom(_root);
        _root = nullptr;
        }

    bool contains(const T & findVal) {
        // TODO: Return t/f if a given value is currently in the tree
        bool found = false;
        AVLNode<T> *tmp = _root;
        while(!found && tmp != nullptr){
            if(tmp->val == findVal) return true;
            if(tmp->val > findVal) tmp = tmp->left;
            else tmp = tmp->right;
        }
        return false;
    }

    int height() {
        if(_root == nullptr) return -1;
        return height(_root);
        // TODO: Return the current height of the tree
        // Remember! A null pointer is height -1
    }

    T findMin() {
        // Return the minimum *value* in the tree (not a tree node)
        AVLNode<T> * tmp = this->_root;
        if(_root != nullptr){
            tmp = _root;
            while(tmp->left != nullptr){
                tmp = tmp->left;
            }
            T value = tmp->val;
            return (T)value; // this is to allow the tests to fail - should definitely be changed
        }
    }

    T findMax() {
        // Return the maximum *value* in the tree (not a tree node)
        if(_root != nullptr){

            AVLNode<T> * tmp;
            tmp = _root;
            while(tmp->right != nullptr){
                tmp = tmp->right;
            }
            T value = tmp->val;
            return (T)value; // this is to allow the tests to fail - should definitely be changed!
        }
    }

    // Prints the tree to ostream out in preorder traversal
    void printPreOrder(std::ostream& out) {
        printPreOrder(this->_root, out);
    }

    int size() {
        return countNodes(_root);
        // TODO: Return the size of the tree (number of nodes in the tree)
    }

// *************** Private /internal function implementation ******* //

private:
    // Should put your various internal balancing, rotating, and calculating functions here

    // Freebie: neat little function to safely get a node's height
    int height( AVLNode<T> * t ) const
    {
        return t == nullptr ? -1 : t->height;
    }

    void deleteAllFrom(AVLNode<T> * t){
        if(t == nullptr){
            return;
        }
        deleteAllFrom(t->left);
        deleteAllFrom(t->right);
        delete t;
    }

    int countNodes(AVLNode<T> * & t){
        if(t == nullptr){
            return 0;
        }
        else{
            return countNodes(t->left) + countNodes(t->right) + 1;
        }
    }

    // Traverses the tree and prints in pre order
    // This is used a lot in the testing system, changing it would be troublesome
    void printPreOrder(AVLNode<T> * & t, std::ostream& out)
    {
        if( t != nullptr )
        {
            out << t->val << " ";
            printPreOrder(t->left, out);
            printPreOrder(t->right, out);
        }
    }

    AVLNode<T> * findMin(AVLNode<T> * & node){
        if(node->left == nullptr)
            return node;
        else
            return findMin(node->left);
    }

    void remove(const T & toDelete, AVLNode<T> * & node){
        if(node == nullptr)
            return;
        else if(toDelete < node->val)
            remove(toDelete, node->left);
        else if(toDelete > node->val)
            remove(toDelete, node->right);
        else if(node->left != nullptr && node->right != nullptr){
            node->val = findMin(node->right)->val;
            remove(node->val, node->right);
        }
        else{
            AVLNode<T> * & oldNode = node;
            node = (node->left != nullptr) ? node->left : node->right;
            delete oldNode;
        }
        balance(node);
    }

    void add(const T & newVal, AVLNode<T> * & node){
        if(node == nullptr){
            node = new AVLNode<T>(newVal);
            node->height = 0;

        }
        else if(newVal > node->val){
            add(newVal, node->right);
        }
        else if(newVal < node->val){
            add(newVal, node->left);
        }
        balance(node);
    }

    AVLNode<T> * rightRotate(AVLNode<T> * & root){
        AVLNode<T> * node1 = root->left;
        root->left = node1->right;
        node1->right = root;
        root->height = max(height(root->left), height(root->right)) +1;
        node1->height = max(height(node1->left), (root->height)) +1;
        return node1;
    }

    AVLNode<T> * leftRotate(AVLNode<T> * & root){
        AVLNode<T> * node1 = root->right;
        root->right = node1->left; //this 
        node1->left = root;
        root->height = max(height(root->right), height(root->left)) +1;
        node1->height = max(height(node1->right), (root->height)) +1;
        return node1;
    }

    AVLNode<T> * doubleRightRotate(AVLNode<T> * & node){
        node->left = leftRotate(node->left);
        node = rightRotate(node);
        return node;
    }

    AVLNode<T> * doubleLeftRotate(AVLNode<T> * & node){
        node->right = rightRotate(node->right);
        node = leftRotate(node);
        return node;
    }



    void balance(AVLNode<T> * & node){
        if(node == nullptr)
            return;
        if(height(node->left)- height(node->right) > 1){
            if(height(node->left->left) >= height(node->left->right))
                node = rightRotate(node);
            else
                node = doubleRightRotate(node);
        }
        if(height(node->right)- height(node->left) > 1){
            if(height(node->right->right) >= height(node->right->left))
                node = leftRotate(node);
            else
                node = doubleLeftRotate(node);
        }
        node->height = max(height(node->left), height(node->right)) + 1;
    }



};




#endif
