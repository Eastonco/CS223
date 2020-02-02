/*
 * ListNode.h - Implements a LinkedList Node
 *
 * Adam Carter - 2015
 * Aaron S. Crandall, 2018 <acrandal@wsu.edu>
 *
 */

#ifndef LIST_NODE_H
#define LIST_NODE_H

// A list node represents a single "box" inside a lined list.  In this 
//  scheme, the LinkedList is simply a collection of ListNode boxes.
template <typename T>
class ListNode
{
protected:

	T _value;           // Value of Templated type that our LL node holds
	ListNode<T> *_next; // Pointer to next node in the LL sequence


public:

	// Constructor must accept a default value
	ListNode(const T &value) : _value(value)
	{
		_next = nullptr;
	}

    // Basic empty ListNode Constructor
	ListNode()
	{
		_next = nullptr;
	}

	// Copy constructor prevents premature deletion of next pointer
	ListNode(const ListNode<T> &other)
	{
		_value = other.getValue();
		_next = other.getNext();
	}


	// Copy operator allows us to reassign previously created list nodes
	virtual ListNode<T> &operator=(const ListNode<T> &other)
	{
		if (this != &other)
		{
            _value = other.getValue();
            _next = other.getNext();
		}
		return *this;
	}

    // Destructor
	virtual ~ListNode()
	{
		_value = 0;
		_next = nullptr;
	}

	// Returns a pointer to the next list node in the sequence
	ListNode<T> *getNext() const
	{
		return _next;
	}

	// Sets the pointer to the next node in the sequence
	void setNext(ListNode<T> *next)
	{
		_next = next;
	}

	// Returns the value of the list node
	T &getValue()
	{
		return _value;
	}

	//constant version of the getter
	const T& getValue() const
	{
		return _value;
	}

	// Sets the value of the current list node
	void setValue(const T &value)
	{
		_value = value;
	}
};

#endif
