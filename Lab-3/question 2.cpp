#include <iostream>
using namespace std;

class Node{
/*consits of data and pointer
	*that ponts the next element in the linked list
	*/

	public:
	int data;
	Node* next;
	Node(){
		data=0;
		next=NULL;
	}
};
class CirLinkedList{
/*
 * Class for the circular linked list data structure.
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
	CirLinkedList(){
		head=NULL;
		tail=NULL;
		n=0;
	
	}
//member functions of this class.
	void insert(int data);// inserts Node with data at the end of the list.

	void insertAt(int pos,int data);//inserts Node at the given position.
	void delt();//deletes the element at the end 
	void deleteAt(int pos);//deletes the element at the position.
    int countItems();//returns the number of items.
void display();//displays the linked list.
  
};

void CirLinkedList:: insert(int data){
/* inserts the element at the end of the list*/
	Node* temp=new Node;
	temp->data=data;

	if(head==NULL)//this is done when the list is empty

	{
		head =temp;
		tail=temp;
	}
	else        //this is done when the list is not empty.
	{
		temp->next=head;
		tail->next=temp;
		tail=temp;
		
	}
	n++;
}
void CirLinkedList:: insertAt(int pos,int data){
	
/*inserts the node with data at the given position.*/

if(pos>n)   //no element is added when the 
	                                    	//position exceeds   //the size of the list


	   cout<<"INVALID CHOICE"; 
	else if(pos==0)
	{
		Node* temp=new Node;
		temp->data=data;  //element is added at the beginning of the list

		temp->next=head;
		tail->next=temp;
		head=temp;
		n++;
	}
	else if(pos==n) //element is added at the end of the list by //calling insert function.

    {
    	insert(data);
    }
    else{
        Node* temp=new Node;
		temp->data=data;//element is added somewhere inof the list

	
		Node* p=head;
		for(int i=0;i<pos-1;i++){//p variable stores the pointer "head" temporarily
	                                           //inorder to proceed forward in the list upto 
	                                           //the position "pos" and add the element there

			p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
		n++;
    }
}
void CirLinkedList::delt()
{/*deletes the last element othe list*/ 
     	Node* p=head;//p variable stores the pointer "head" temporarily
	                                           //inorder to proceed forward in the list.

		for(int i=0;i<n-1;i++){
			p=p->next;
		}
		Node* q;
		q=p->next;
		p->next=head;
		delete q;
		
		
}
void CirLinkedList::deleteAt(int pos)
{
/*no element can be deleted from the position more than the size of the list*/
	if(pos>n)
	 cout<<"INVALID CHOICE";
//deletes the element at beginning.
	else if(pos==0)
	{
		Node* p=head;
		head=p->next;
		tail->next=head->next;
		delete p;
	}
	
	else{
		 Node* p=head; //p stores head temporarily

		 for(int i=0;i<pos-1;i++)
		 {
		 	p=p->next;
		 }
		 Node* q; //q variable stores (pos-1)th element

		 q=p->next;
		 p->next=q->next;
		 delete q;
		 
	}
	n--;
}
int CirLinkedList::countItems()
{
	return n; //returns the size of the list

}
 
void CirLinkedList :: display()
{/*prints the values of the nodes in the list*/
            Node* p=new Node;p=head;
            for(int i=0;i<n-1;i++)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
 
	cout<<p->data<<endl;
}
 
int main()
{
/*to execute the members functions*/
	CirLinkedList cir1;
 
	for(int i=0;i<10;++i)
	{
		cir1.insert(i+1);
	}
 
	cir1.insertAt(6,9);
	cir1.deleteAt(3);
	cir1.display();
	cout<<"The number of elements in the circular linked list are "<<cir1.countItems()<<endl;
 
	return 0;
}
 
