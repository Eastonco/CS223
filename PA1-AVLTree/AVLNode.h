/*
 *  AVL Node class
 * 
 *  Contributors:
 *   Aaron S. Crandall <acrandal@wsu.edu> - 2018
 */


#ifndef __AVLNODE_H
#define __AVLNODE_H

template <typename T>
class AVLNode
{
    public:
        T val;
        AVLNode * left;
        AVLNode * right;
        int height;

        static int nodeCount;

    /* Constructor takes both the new value and pointers to children */
    AVLNode( const T & newVal, 
                AVLNode * newLeft, 
                AVLNode * newRight, 
                int h = 0 ) 
                    : val( newVal ), left(newLeft), right(newRight), height(h) 
                    {
                        nodeCount++;
                    }

    /* Constructor takes only a new value */
    AVLNode( const T & newVal )
                    : val( newVal ), left(nullptr), right(nullptr), height(0)
                    {
                        nodeCount++;
                    }
    ~AVLNode()
    {
        nodeCount--;    // Leave in for testing total nodes created/destroyed
                        // You can add more contents if you need
    }
};

// Initialize the static class variable nodeCount - also allocates memory for it
template <typename T>
int AVLNode<T>::nodeCount = 0;

#endif
