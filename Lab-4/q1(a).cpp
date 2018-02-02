#include<iostream>
using namespace std;

class Node {
	/*class Node to create a pointer
	*that points to next element of the queue and data
	*that has to be stored in the node */

	public:
		int data;
		Node* next;

		Node() {   //constructor.
			data = 0;
			next = NULL;
		}
};

class Stack {
	/*
 * Class for Stack data structure.
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
		Stack() {        //Constructor.
			head = NULL;
			tail = NULL;
			n = 0;
		}

		void push(int x);
		void pop();
		void display();
};

void Stack::push(int x) {
	
/*
 * Inserts a new Node 
 * at the end of the Stack.
 */

	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;

	if (head == NULL) {      //Steps done when the Stack is empty

		head = temp;
		tail = temp;
		++n;
	} else {         //Steps done when the Stack is not empty

		tail->next = temp;
		tail = temp;
		++n;
	}
}

void Stack::pop() {
	/*Remove the node from the end in the Stack.*/
	Node* temp= head;
	for (int j=0; j<n-2; ++j)
		temp=temp->next;

	temp->next = NULL;
	tail = temp;
	--n;
}

void Stack::display() {
	/* 
 * Displays all the elements of the linked list.
 */

	if (head == NULL) {
		cout << "There are no elements in the stack." << endl;
	} else {
		Node*p = head;
		while(p != NULL) {
			cout << p->data <<"->";
			p = p->next;
		}
		cout<<"NULL"<<endl;
	}
}

int main() {
	/*main function to check
	*whether the code is correct or not*/

	Stack s1;
	int p=0;
	cout << "Enter five elements to the list: " << endl;
	for (int i=0; i<5; ++i) {
		cin >> p;
		s1.push(p);
	}

	s1.display();
	s1.push(25);
	s1.display();
	s1.pop();
	s1.display();

	return 0;
}
