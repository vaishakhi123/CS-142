#include<iostream>
using namespace std;

class Node {
	/*consits of data and pointer
	*that ponts the next element in the linked list
	*/
	public:
		int data;
		Node* next;

		Node() {
			data = 0;
			next = NULL;
		}
};

class SLinkedList {
	
	/*consits of pointer head  that points to first element of the
	*list and tail ponter that points null respectively and a variable "n" 
	*that stores the size of the list
	*/
	private:
		Node* head;
		Node* tail;
		int n;

	public:
		SLinkedList() {
			head = NULL;
			tail = NULL;
			n = 0;
		}
                        /*memeber functions of the class "SLinkedList"*/
		void insert(int x);
		void insertAt(int pos,int x);
		void deleteN();
		void deleteAt(int pos);
		int countItems();
		void display();
};

void SLinkedList::insert(int x) {  
	
	/* inserts the element at the end of the list*/
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;

	if (head == NULL) {
		head = temp; //this is done when the list is empty
		tail = temp;
		++n;
	} else {
		tail->next = temp;  //this is done when the list is non-empty
		tail = temp;
		n++;
	}
}

void SLinkedList::insertAt(int pos, int d) {
	
	
	if (pos > n) {
		cout << "Invalid index." << endl; //no element is added when the 
	                                    	//position exceeds the size of the list

	} 

	else if (pos == 0) {
		Node* temp = new Node;
		temp->data = d;        	//element is added at the beginning of the list
		temp->next = head;
		head = temp;
		++n;

	}
	//element is added ath the end of the list by calling the above function "insert"
	else if (pos == n) {
	     insert(d);

	} 
	//element is added anywhere in the list
	else {
		Node* temp = new Node;
		temp->data = d;

		Node* p = head;                 //p variable stores the pointer "head" temporarily
	                                           //inorder to proceed forward in the list upto 
	                                           //the position "pos" and add the element there

		for (int i=0; i<pos-1; ++i) {  
	                                           
			p = p->next;
		}

		temp->next = p->next;
		p->next = temp;
		++n;
	}
}

void SLinkedList::deleteN(){
	/*deletes the last element of the list*/ 
			Node* temp=head;
			for(int i=0;i<n-1;i++)
			{
				temp=temp->next;
			}
			Node* p=temp->next;
			temp->next=NULL;
			delete p;
		
}


void SLinkedList::deleteAt(int pos){
	/*no element can be deleted from the position more than the size of the list*/
	if(pos>n){
		cout<<"invalid choice";}
		
		//deletes the element at beginning
		else if(pos==0){
			Node* temp=new Node;
			temp=head->next;
			delete temp;
		}
		
	
		else{
			Node* temp=head;  //temp stores head temporarily
		
		for (int i=0; i<pos-1; i++) {
			temp= temp->next;  
		}
                        Node* p=temp->next;  //p variable stores (pos-1)th element
		temp->next = p->next;
		delete p;
		}
		n--;
}

int SLinkedList::countItems(){
	return n;   //returns the size of the list
}
void SLinkedList::display() {
	/*prints the values of the nodes in the list*/
		Node* temp = new Node;
		temp = head;
		
		while (temp != NULL) {
			cout << temp->data<<"->" ;
			temp = temp->next;}
			cout<<"NULL"<<endl;
		
	
}

int main() {
	
/*to execute the member function */
SLinkedList l1;
for (int i=0; i<5; ++i) {
		l1.insert(i+1);
	}
	l1.insertAt(3,1);
	l1.deleteAt(2);
	l1.display();
	cout <<"the number of items in the linked list is "<< l1.countItems() << endl;
 
	

	return 0;
}
