/*
 * Binary Search Tree implementation 
 *  - heavily lifted from https://gist.github.com/mgechev/5911348
 *  - though, very very hacked up since then
 *
 * Simple keys and basic operations BST
 *
 * Aaron Crandall - 2016 - Added / updated:
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 * Aaron Crandall - 2017 - Heavy overhaul of tests & behaviors
 *  * Added BigFive (like we should!)
 *  * Added several public interfaces for tree features
 * Aaron Crandall - 2019 - Fixed -Wshadow errors
 *  * Identified a few badly done interface fixes
 *
 */

#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <cstring>		// strcmp
#include <vector>
#include <queue>
#include <initializer_list>

using namespace std;


/*
 *  Datastructure for a single tree node
 */ 
template <typename T>
struct Node {
public:
    T value;
    Node *left;
    Node *right;

    static int nodeCount;

    Node(T val) {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
        nodeCount++;
    }

    Node(T val, Node<T> * setLeft, Node<T> * setRight) {
        this->value = val;
        this->left = setLeft;
        this->right = setRight;
        nodeCount++;
    }

    ~Node()
    {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
        nodeCount--;
    }
};

// Initialize the static class variable for counting nodes to zero
template <typename T>
int Node<T>::nodeCount = 0;

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

    protected:
    Node<T> *_root;         // Root of the tree nodes
    bool _debug = false;    // Enable extra output

    /* Clone a passed in tree, returns pointer to new tree */
    Node<T> * cloneTree(Node<T> *t) {
        if( t == nullptr )
            return nullptr;
        else
            return new Node<T>( t->value, 
                                cloneTree( t->left ),
                                cloneTree( t->right ) );
    }

    /* Recursively delete the tree nodes */
    void makeEmptyHelper(Node<T> *t) {
        if( t != nullptr ) {
            makeEmptyHelper( t->left );
            makeEmptyHelper( t->right );
            delete t;
        }
    }

    /* Add new T val to the tree */
    void addHelper(Node<T> *root, T val) {
        if (root->value > val) {
            if (!root->left) {
                root->left = new Node<T>(val);
            } else {
                addHelper(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = new Node<T>(val);
            } else {
                addHelper(root->right, val);
            }
        }
    }

    /* Print tree out in inorder (A + B) */
    void printInOrderHelper(Node<T> *root, std::ostream& out) {
        if (!root) return;
        printInOrderHelper(root->left, out);
        out << root->value << ' ';
        printInOrderHelper(root->right, out);
    }

    /* Print tree out in post order (A B +) */
    void printPostOrderHelper(Node<T> *root, std::ostream& out) {
        if (!root) return;
        printPostOrderHelper(root->left, out);
        printPostOrderHelper(root->right, out);
        out << root->value << ' ';
    }

    /* Print tree out in pre order (+ A B) */
    void printPreOrderHelper(Node<T> *root, std::ostream& out) {
        if (!root) return;
        out << root->value << ' ';
        printPreOrderHelper(root->left, out);
        printPreOrderHelper(root->right, out);
    }

    /* Print tree out in level order */
    /* MA TODO: Implement */
    void printLevelOrderHelper(Node<T> *root, std::ostream& out) {
        if (!root) return;
        out << endl;

        //out << " ** Required to use the STL queue class (that's a huge hint)!" << endl;
        //out << " ** Doing this with a loop will be easier than recursion." << endl;
        //out << " ** Your code MUST print to 'out' not 'cout' to work - see printInOrder()." << endl;
        
        queue <Node<T> *> q;
        q.push(root);
        while(q.size() > 0){
            int queueSize = q.size();

            while(queueSize > 0){

            Node<T> * node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            out << node->value << " ";
            queueSize--;
            }
        }

        
        

        

    }


    /* Return number of nodes in tree */
    int nodesCountHelper(Node<T> *root) {
        if (!root) {
            return 0;
        } else {
            return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
        }
    }

    /* Return height of tree (root == nullptr -> 0) */
    int heightHelper(Node<T> *root) {
        if (!root) {
            return -1;
        } else {
            return 1 + max(heightHelper(root->left), heightHelper(root->right));
        }
    }

    /* Print out longest path from root to a leaf */
    void printMaxPathHelper(Node<T> *root) {
        if (!root) return;
        cout<<root->value<<' ';
        if (heightHelper(root->left) > heightHelper(root->right)) {
            printMaxPathHelper(root->left);
        } else {
            printMaxPathHelper(root->right);
        }
    }

    /* Delete a given <T> value from tree */
    bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
        if (!current) return false;
        if (current->value == value) {
            if (current->left == nullptr || current->right == nullptr) {
                Node<T>* temp = current->left;
                if (current->right) temp = current->right;
                if (parent) {
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                } else {
                    this->_root = temp;
                }
            } else {
                Node<T>* validSubs = current->right;
                while (validSubs->left) {
                    validSubs = validSubs->left;
                }
                T temp = current->value;
                current->value = validSubs->value;
                validSubs->value = temp;
                return deleteValueHelper(current, current->right, temp);
            }
            delete current;
            return true;
        }
        return deleteValueHelper(current, current->left, value) ||
               deleteValueHelper(current, current->right, value);
    }

    bool containsHelper(Node<T> * root, T val) {
        if( root == nullptr )
            return( false );
        else if( root->value == val )
            return( true );
        else if( root->value > val ) // Search left
            return( containsHelper(root->left, val) );
        else
            return( containsHelper(root->right, val) );
    }


    /********************************* PUBLIC API *****************************/
    public:

    BST( ) : _root( nullptr ) { }               // Basic initialization constructor

    BST( initializer_list<T> vals ) : _root( nullptr ) {
        for( auto val : vals )
            { this->add(val); }
    }


    /* Destructor - Needs to free *all* nodes in the tree */
    /* MA TODO: Implement */
    ~BST( ) {
        if( this->_debug ) {
          //  cout << " TODO: Implement destructor to free *whole* tree. " << endl;
        }
        makeEmpty();
        
    }

    /* Copy constructor */
    /* MA TODO: Implement */
    BST( const BST &other ) : _root( nullptr ) {
        if( this->_debug ) {
            cout << " [d] Copy constructor called. " << endl;
        }
        //cout << " TODO: Implement copy constructor. " << endl;

        this->_root = cloneTree(other._root);

    }

    /* Move constructor */
    /* MA TODO: Implement */
    BST ( BST && other ) : _root( nullptr ) {
        if( this->_debug ) {
            cout << " [d] Move constructor called " << endl;
        }
        //cout << " TODO: Implement move constructor. " << endl;

        this->_root= other._root;
        other._root = nullptr;

    }

    /* Copy assignment operator */
    /* MA TODO: Implement */
    BST& operator=(BST & other) {
        if( this->_debug ) {
            cout << " [d] Copy assignment operator called. " << endl;
        }
       // cout << " TODO: Implement copy assignment operator. " << endl;

        this->_root = cloneTree(other._root);

        return * this;
    }

    /* Move assignment operator */
    /* MA TODO: Implement */
    BST& operator=(BST && other) {
        if( this->_debug ) {
            cout << " [d] Move assignment operator called. " << endl;
        }
        //cout << " TODO: Implement move assignment operator. " << endl;
        makeEmpty();

        this->_root= other._root;
        other._root = nullptr;

        return * this;
    }

    /* Public API */
    void makeEmpty( ) {
        if (this->_root) 
            this->makeEmptyHelper(this->_root);
        this->_root = nullptr;
    }

    void add(T val) {
        if (this->_root) {
            this->addHelper(this->_root, val);
        } else {
            this->_root = new Node<T>(val);
        }
    }

    bool empty() {
        return( this->_root == nullptr );
    }

    // The print functions take an *optional* ostream handle
    // Not providing one will have them default to std::cout (the terminal)
    void print(std::ostream& out=std::cout) {
        printInOrderHelper(this->_root); 
    }

    void printInOrder(std::ostream& out=std::cout) {
        printInOrderHelper(this->_root, out);
    }

    void printPostOrder(std::ostream& out=std::cout) {
        printPostOrderHelper(this->_root, out);
    }

    void printPreOrder(std::ostream& out=std::cout) {
        printPreOrderHelper(this->_root, out);
    }

    void printLevelOrder(std::ostream& out=std::cout) {
        printLevelOrderHelper(this->_root, out);
    }

    vector<T> & returnLevelOrder() {
        return returnLevelOrderHelper(this->_root);
    }

    int size() {
        return nodesCount();
    }
    int nodesCount() {
        return nodesCountHelper(this->_root);
    }

    int height() {
        return heightHelper(this->_root);
    }

    void printMaxPath() {
        printMaxPathHelper(this->_root);
    }

    bool deleteValue(T value) {
        return this->deleteValueHelper(nullptr, this->_root, value);
    }

    bool contains( T value ) {
        return containsHelper(this->_root, value);
    }

    void debug_on() {
        this->_debug = true;
    }

    void debug_off() {
        this->_debug = false;
    }
};


#endif
