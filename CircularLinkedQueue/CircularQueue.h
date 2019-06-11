#pragma once
#include <iostream>
using namespace std;

// CircularQueue template
template <class T>
class CircularQueue
{
private:
	// Structure for the queue nodes
	struct QueueNode
	{
		T value;			// Value in a node
		QueueNode *next;	// Pointer to the next node
	};

	QueueNode *rear;		// The rear of the queue
	int numItems;			// Number of items in the queue
	int maxItems;			// Maximum number of items allowed in the queue
public:
	// Constructor
	CircularQueue(int);

	// Destructor
	~CircularQueue();

	// Queue operations
	void enqueue(T);
	void dequeue(T&);
	bool isEmpty() const;
	bool isFull() const;
	void makeEmpty();
	void printQueue();
};

//********************************************
// The constructor creates an empty queue.   *
//********************************************
template <class T>
CircularQueue<T>::CircularQueue(int max)
{
	rear = new QueueNode;
	numItems = 0;
	maxItems = max;
}

//*********************************************
// Destructor deletes each item in the queue. *                                
//*********************************************
template <class T>
CircularQueue<T>::~CircularQueue()
{
	makeEmpty();
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
template <class T>
void CircularQueue<T>::enqueue(T item)
{
	if (isFull())
	{
		cout << "\nERROR: Enqueue on full queue.\n";
	}
	else {
		QueueNode *newNode = nullptr;

		// Create a new node and store item there.
		newNode = new QueueNode;
		newNode->value = item;
		newNode->next = nullptr;

		// Adjust front and rear as necessary.
		if (isEmpty())
		{
			newNode->next = newNode;
			rear = newNode;
		}
		else
		{
			newNode->next = rear->next;
			rear->next = newNode;
			rear = newNode;
		}

		// Update numItems.
		numItems++;
	}
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
template <class T>
void CircularQueue<T>::dequeue(T& item)
{
	QueueNode *temp = nullptr;

	if (isEmpty())
	{
		cout << "\nERROR: Dequeue on empty queue.\n";
	}
	else
	{
		// Save the front node value in item.
		item = rear->next->value;

		// Remove the front node and delete it.
		temp = rear->next;
		rear->next = temp->next;
		delete temp;

		// Update numItems.
		numItems--;
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
template <class T>
bool CircularQueue<T>::isEmpty() const
{
	bool status;
	if (numItems > 0)
		status = false;
	else
		status = true;
	return status;
}

//**********************************************
// Function isFull returns true if the queue   *
// is full, and false otherwise.			   *
//**********************************************
template<class T>
bool CircularQueue<T>::isFull() const
{
	bool status;
	if (numItems >= maxItems)
		status = true;
	else
		status = false;
	return status;
}

//***********************************************
// Function makeEmpty dequeues all the elements *
// in the queue.                                *
//***********************************************
template <class T>
void CircularQueue<T>::makeEmpty()
{
	T value;   // Dummy variable for dequeue

	while (!isEmpty())
		dequeue(value);
}

//***********************************************
// Function printQueue prints all the elements  *
// in the queue, in order as First-In-First-Out *
//***********************************************
template <class T>
void CircularQueue<T>::printQueue()
{
	QueueNode *nodePtr = rear;
	if (numItems <= 0)
		return;
	else
	{
		cout << "Circular Queue\n";
		do
		{
			nodePtr = nodePtr->next;
			cout << "  " << nodePtr->value << endl;
		} while (nodePtr != rear);
	}
}

