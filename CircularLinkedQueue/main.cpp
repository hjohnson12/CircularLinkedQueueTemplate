/*
Programmer: Hunter Johnson
Name: Circular Linked Queue
Info: rear->next is supposed to reference front of the queue
Class: CIS 250-01
Date: 3/2/2017
*/
#include <iostream>
#include <string>
#include "CircularQueue.h"
using namespace std;

// Constant
const int QUEUE_SIZE = 5;

int main()
{
	cout << "Assignment: Circular Linked Queue" << endl << endl;
	const int ENQUEUE_CHOICE = 1;	// Menu Choice 1
	const int DEQUEUE_CHOICE = 2;	// Menu Choice 2
	const int QUIT_CHOICE = 3;		// Menu Choice 3
	int choice;						// User's menu choice	
	string value;					// Value to enqueue, and dummy variable for dequeue

	CircularQueue<string> cQueue(QUEUE_SIZE);	// Create a CircularQueue object.

	// Display Menu
	do
	{
		// Get user's menu choice
		cout << "(1=enqueue, 2=dequeue, 3=quit): ";
		cin >> choice;

		// Validate choice
		while (choice < ENQUEUE_CHOICE || choice > QUIT_CHOICE)
		{
			cout << "Enter a valid choice: ";
			cin >> choice;
		}

		// Perform the choice
		if (choice != QUIT_CHOICE)
		{
			switch (choice)
			{
			case ENQUEUE_CHOICE:
				cout << "Value to enqueue: ";
				cin >> value;
				cQueue.enqueue(value);			// Enqueue value onto queue
				cQueue.printQueue();
				break;
			case DEQUEUE_CHOICE:
				cQueue.dequeue(value);			// Dequeue value from queue
				cQueue.printQueue();
				break;
			}
		}
	} while (choice != QUIT_CHOICE);

	system("pause");
	return 0;
}
