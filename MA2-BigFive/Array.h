#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>
#include <initializer_list>
#include <exception>
#include <utility>
#include "Indexed.h"
using namespace std;

template <typename T>
class Array : public Indexed<T>
{
	//made protected in order to give access to Vector
protected:

	//_items will handle the actual storage
	//of our data items.
	T *_items;

	//used to store the maximum size of
	//our array
	int _max_size;

	//tracks the ACTUAL number of items
	//in our array
	int _number_of_items;

public:

#pragma region constructors / destructors

	//constructor with single input paramter.  Need to initialize using ()
	//to call this one
	Array(int max_size)
	{
		_max_size = max_size;
		_number_of_items = 0;
		_items = new T[_max_size];
	}

	//initializer list constructor
	Array(initializer_list<T> values)
	{
		_max_size = values.size();
		_number_of_items = 0;
		_items = new T[_max_size];

		//cool C++ 11 way to iterate!
		for (auto item : values)
		{
			addElement(item);
		}
	}

	//Copy constructor.  
	Array(const Array<T> &other)
		: _items(nullptr)
	{
		//don't copy ourselves!
		if (this != &other)
		{
			//delete existing contents if they exit
			if (_items != nullptr)
			{
				delete[] _items;
			}

			//allocate space for new items
			_max_size = other.getSize() + 1;
			_number_of_items = other.getSize();
			_items = new T[_max_size];

			//make copies of other's items
			for (int i = 0; i < _number_of_items; i++)
			{
				T item = other.getElementAt(i);
				_items[i] = item;
			}
		}
	}

	//Move constructor. 
	Array(Array<T> &&other)
		: _items(nullptr)
	{
		//get other's meta data
		_max_size = other._max_size;
		_number_of_items = other._number_of_items;

		//then steal its pointer
		_items = other._items;

		//and give it nullptr instead
		other._items = nullptr;
	}


	//We need to delcare a destructor because we're dynamically allocating memory
	//in our constructor
	virtual ~Array()
	{
		if (_items != nullptr)
		{
			delete[] _items;
		}
	}

#pragma endregion

	//methods that originally came from the Collection interface
#pragma region Collection overrides

	//Will return true if we have no items in our Array.  False otherwise.
	virtual bool isEmpty() const
	{
		return _number_of_items == 0;
	}

	//Returns the number of items currently in the array.  Note that
	//there still might be NULL values that exist within this range.
	virtual int getSize() const
	{
		return _number_of_items;
	}

	//adds an item to the "end" of our array
	virtual void addElement(T item)
	{
		//add element to the end of our array
		addElementAt(item, _number_of_items);
	}
#pragma endregion

	//methods that originally came from the Indexed interface
#pragma region Indexed overrides

	//returns the item at the specified index
	virtual T& getElementAt(int location)
	{
		if (location < 0 || location >= _number_of_items)
		{
			throw out_of_range("Index out of range.");
		}
		return _items[location];
	}

	//const version of getElementAt
	virtual const T &getElementAt(int index) const
	{
		if (index < 0 || index >= _number_of_items)
		{
			throw out_of_range("Index out of range.");
		}
		return _items[index];
	}

	//sets the item at the specified index
	virtual void setElementAt(T value, int location)
	{
		if (location < 0 || location >= _max_size)
		{
			throw out_of_range("Index out of bounds.");
		}
		_items[location] = value;

		//if this index is larger than our currently tracked _number_of_items,
		//replace with specified index
		if (_number_of_items <= location)
		{
			_number_of_items = location + 1;
		}
	}

	//adds the item at the specified index and shifts all larger items
	//"right" by one
	virtual void addElementAt(T value, int location)
	{
		//make sure that we're not full and that the index is within bounds
		if (location >= _max_size)
		{
			throw out_of_range("Array index out of bounds.");
		}
		if (_number_of_items == _max_size)
		{
			throw exception("Array is at max size.");
		}

		//shift every item to the right
		//worst case is location == 0
		//best case is location == number of items
		for (int i = _number_of_items - 1; i >= location; i--)
		{
			setElementAt(_items[i], i + 1);
		}

		//now that we have a spot for our item, add it to our array
		setElementAt(value, location);
	}

	//removes the item at the specified index and shifts all smaller items
	//"left" by one
	virtual void removeElementAt(int index)
	{
		//make sure that we're in bounds
		if (index < 0 || index >= _max_size)
		{
			throw out_of_range("Index out of bounds.");
		}

		//shift everything left
		//worst case: index == 0
		//best case:  index == number of items
		//O(N) - N = size of array
		for (int i = index; i < _number_of_items - 1; i++)
		{
			_items[i] = _items[i + 1];
		}

		//do the last shift if we have room
		if (_number_of_items + 1 < _max_size)
		{
			_items[_number_of_items] = _items[_number_of_items + 1];
		}

		//decrement the number of items in our array
		_number_of_items--;
	}
#pragma endregion

#pragma region Array-specific functions

	//The setSize method for Arrays won't actually change the underlying size of the array.
	//Instead, it merely readjusts the number of items being tracked in the array.
	virtual void setSize(int size)
	{
		//check for exceptions!
		if (size < 0 || size > _max_size)
		{
			throw out_of_range("Invalid size.");
		}
		_number_of_items = size;
	}

#pragma endregion

#pragma region operator overloads

	//Copy operator 
	virtual Array<T> & operator=(const Array<T> &other)
	{
		//remove existing items if we have any
		if (this->_items != nullptr)
		{
			delete[] _items;
		}

		//allocate new space
		_items = new T[other.getSize()];
		
		//copy other's meta data
		_max_size = other._max_size;
		_number_of_items = other._number_of_items;

		//copy other's items
		for (int i = 0; i < other.getSize(); i++)
		{
			setElementAt(other.getElementAt(i), i);
		}

		//Kind of goofy syntax, but we need to return a reference to ourselves.  Recall that
		//"this" refers to whatever object is calling this code.  Also recall that "this"
		//is a pointer, so we have to dereference us in order to return ourselves as a 
		//reference.
		return *this;
	}

	//Move operator
	virtual Array<T> &operator=(Array<T> &&other)
	{
		//take care of any information we already have before stealing other's data
		if (_items != nullptr)
		{
			delete[] _items;
		}

		//get other's meta data
		_max_size = other._max_size;
		_number_of_items = other._number_of_items;

		//then steal its pointer
		_items = other._items;

		//and give it nullptr instead
		other._items = nullptr;

		//return a reference to ourselves
		return *this;
	}

	//shortcut for getElementAt
	virtual T&  operator[](int index)
	{
		return _items[index];
	}

	//shortcut for getElementAt
	virtual const T& operator[](int index) const
	{
		return _items[index];
	}

#pragma endregion
};

#endif