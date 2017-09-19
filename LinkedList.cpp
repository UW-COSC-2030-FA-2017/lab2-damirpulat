// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

// Damir Pulatov
// COSC 2030
// Lab2
// 09/18/17

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}


const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


void List::insertAsLast(double x)
{

	if (!empty())
	{
		// Keep track of last node
		Node *last = first_;

		// Traverse through the list
		while (last->next_ != NULL)
		{
			last = last->next_;
		}

		// Create a new last node and update previous last node
		Node *newLast = new Node(x);
		newLast->next_ = NULL;
		last->next_ = newLast;
	}
	else
	{
		// If list is empty, use insertAsFirst method
		insertAsFirst(x);
	}
	return;
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


int List::size() const
{
	int size = 0;

	// Check if list is empty first
	if (!empty())
	{
		// Traverse through list
		Node *tmp = first_->next_;
		size++;
		while (tmp != NULL)
		{
			size++;
			tmp = tmp->next_;
		}
	}


	return size;

}


double List::sum() const
{
	double sum = 0;

	// Check if list is empty first
	if (!empty())
	{
		// Store first number
		sum = first_->entry_;

		// Traverse through list
		Node *tmp = first_->next_;
		
		while (tmp != NULL)
		{
			sum = sum + tmp->entry_;
			tmp = tmp->next_;
		}

	}


	return sum;
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}


