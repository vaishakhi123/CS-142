#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node(){
		data=0;
		next=NULL;
	}
};
class CirLinkedList{
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
	void insert(int data);
	void insertAt(int pos,int data);
	void delt();
	void deleteAt(int pos);
    int countItems();void display();
  
};

void CirLinkedList:: insert(int data){
	Node* temp=new Node;
	temp->data=data;

	if(head==NULL)
	{
		head =temp;
		tail=temp;
	}
	else
	{
		temp->next=head;
		tail->next=temp;
		tail=temp;
		
	}
	n++;
}
void CirLinkedList:: insertAt(int pos,int data){
	if(pos>n)
	   cout<<"INVALID CHOICE";
	else if(pos==0)
	{
		Node* temp=new Node;
		temp->data=data;
		
		temp->next=head;
		tail->next=temp;
		head=temp;
		n++;
	}
	else if(pos==n)
    {
    	insert(data);
    }
    else{
        Node* temp=new Node;
		temp->data=data;
	
		Node* p=head;
		for(int i=0;i<pos-1;i++){
			p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
		n++;
    }
}
void CirLinkedList::delt()
{
     	Node* p=head;
		for(int i=0;i<n-1;i++){
			p=p->next;
		}
		Node* q;
		p=q->next;
		p->next=head;
		delete q;
		
		
}
void CirLinkedList::deleteAt(int pos)
{
	if(pos>n)
	 cout<<"INVALID CHOICE";
	else if(pos==0)
	{
		Node* p=head;
		head=p->next;
		tail->next=head->next;
		delete p;
	}
	
	else{
		 Node* p=head;
		 for(int i=0;i<pos-1;i++)
		 {
		 	p=p->next;
		 }
		 Node* q;
		 q=p->next;
		 p->next=q->next;
		 delete q;
		 
	}
	n--;
}
int CirLinkedList::countItems()
{
	return n;
}
 
void CirLinkedList :: display()
{
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
 
