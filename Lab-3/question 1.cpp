#include<iostream>
using namespace std;

class Node {
/*
 * Node class with a variable data to store data and two pointers
 *for next and the previous node
 */
	public:
		int data;
		Node* next;
		Node* prev;

		Node() {				// Default constructor for Node
			data = 0;			
			next = NULL;
			prev = NULL;		
		}
};

class DLinkedList {
/*
 * Class for the double linked list data structure.
 * Contains two pointers namely head and tail, which point
 * to the first and the last element of the list.
 * A integer variable named size stores the number of
 * items of the linked list.
 */
	private:
		Node* head;
		Node* tail;
		int n;

	public:
		DLinkedList() {				// Default constructor for DLList
			head = NULL;
			tail=NULL;
			n=0;
		}

		// Member functions of the class
		void insert(int data);			// inserts Node with data at the end of the list
		Node* sendNode(int x);		// returns a pointer 
		void insertAt(int pos, int data);	// inserts Node with data at the ith position
		void del();				// removes the last Node of the list
		void deleteAt(int pos);		// removes the ith element of the list
		int countItems();			// return the number of Nodes in the list
		void display();				// displays the elements of the linked list
};

void DLinkedList::insert(int data) {
/*
 * Inserts a new Node 
 * at the end of the linked list.
 */
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;

	if (head == NULL) {				// Checks if the list is empty.
		temp->prev = NULL;		
		head = temp;			
	} else {	
		tail->next = temp;		// Steps to do if there are some
		                                      //elemnts already in the list
             	temp->prev = tail;	
	}

	tail = temp;
	n++;							// Size of the linked list is increased by one.
}

Node* DLinkedList::sendNode(int x) {
/*
 * Function which returns a pointer to the xnode
 * of the linked list.
 */
	if (x < 1 || x > n) {		
		cout << "Invalid element position." << endl;
		return NULL;
	}

	Node* p;						// variable that hold the value temporirly.



	if (x < (n/2)) {
		p = head;					// List proceeds from head
		for (int i=0; i<x-1; ++i)
			p = p->next;

	} else {
		p = tail;					// List proceeds from tail
		for (int i=0; i<(n-x); ++i)
			p = p->prev;
	}

	return p;
}

void DLinkedList::insertAt(int pos, int data) {
/* 
 * Inserts a Node with data at the given position
 */
	if (pos < 1 || pos > n+1) 		
		cout << "Invalid choice." << endl;
		
	

	if (pos== n+1) 				// Calls insert function 
		insert(data);					
	
	

	Node* temp = new Node;
            temp->data = data;

	if (n == 1) {			// adding Node at the start
		temp->next = head;		// of the list.
		temp->prev = NULL;
		head->prev = temp;
		head = temp;
	} else {				// adding Node in the middle
		Node* p = sendNode(pos-1);		// of the list by calling sendNode function.
		temp->next = p->next;
		temp->prev = (p->next)->prev;
		(p->next)->prev = temp;
		p->next = temp;
	}

	n++;					// Increments to size variable to track the number of Nodes

}

void DLinkedList::del() {
/* 
 * Removes the last Node of the linked list.
 */
	if (n == 0) 		
		cout << "list is empty" << endl;
		
	 else if (n == 1) {		
		delete head;			// there is only one Node in the list.
		head = NULL;
		tail = NULL;
	} else {
		Node* p = tail;			// variable p temporarily stores tail to delete 
		delete p;				// the node from memory.
		tail = tail->prev;
		tail->next = NULL;
	}

	--n;
}

void DLinkedList::deleteAt(int pos) {
/*
 * Removes the ith element of the list.
 */
	if (pos < 1 || pos > n) 
		cout << "Invalid choice." << endl;
		
	
	if (pos == n) 		// Calls the del function 
		del();			
              else if (pos == 1) {	                          //  deletion of first element
		head = head->next;
		delete head->prev;
		head->prev = NULL;
	} else {				// Steps for deletion of an element in the middle.
		Node* p = sendNode(pos);
		(p->prev)->next = p->next;
		(p->next)->prev = p->prev;
		delete p;
	}

            n--;					

}

int DLinkedList::countItems() {
/*
 * Counts the number of Nodes in the linked list.
 
 */
	return n;
}

void DLinkedList::display() {
/* 
 * Displays all the elements of the linked list.
 */
	if (n == 0) {			
		cout << "List is empty" << endl;
	}

	Node* p = head;			
	for (int i=0; i<n; ++i) {
		cout << p->data << "->";
		p = p->next;
	}

	cout << "NULL" << endl;
}

int main() {
	DLinkedList list;
	for(int i=0; i<10; ++i) {
		list.insert(i+1);
	}

	list.display();
	list.insertAt(6,7);
	list.deleteAt(5);
	list.deleteAt(8);
	list.display();
	cout << list.countItems() << endl;

	return 0;
}
