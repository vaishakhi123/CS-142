/*Implement Binary search function. Include
Function that takes in array, size of array and element to be searched. Returns the index of the array where the element is found or -1 if the element is not found. 
Function that takes in linked list and element to be searched. Returns the index of the array where the element is found or -1 if the element is not found. */
#include <iostream>
using namespace std;
//creating a class node and defining what a node is
class node
{
 public:
 int data;
 node *next;
};
//creating a linked list
class linkedList
{
 public:
 int n=0;
 node *head,*tail;
 linkedList()		//constructor to initialize the variables
 {
  head=NULL;
  tail=NULL;
 }
 void insert(int data)		//adds element to the linked list 
 {
  node *temp=new node;
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)		//checking if the list is empty
  {
   head=temp;
   tail=temp;
  }
  else
  {
   tail->next=temp;
   tail=temp;
  }
  n++;
 }
 void display()		//displays the linked list
 {
  node *temp=head;
  while(temp!=NULL)
  {
   cout<<temp->data<<" ";
   temp=temp->next;
  }
 }
};

int bsearchLL(node *head,node *tail,int key,int lsize,int rsize)		//function to implement binary search in linked list
{
 int mid=(lsize+rsize)/2;
 node *temp=head;
 for(int i=1;i<mid-1;i++)		//goes upto the previous node of mid
 {
  temp=temp->next;
 }
 if(key<=tail->data && key>=head->data)		//checking if the key is within the linked list
 {
  if(key==temp->next->data)
  {
   cout<<"\nFound at node no ";
   return mid;
  }
  else
  {
   if(key<temp->next->data)
   {
   	bsearchLL(head,temp,key,lsize,(mid-1));		//calling to the nodes to the left of the middle node
   }
   else
   {
   	bsearchLL(temp->next->next,tail,key,(mid+1),rsize);		//calling to the nodes to the right of the middle node
   }
  }
 }
 else
 {
  cout<<"\nNot found ";
  return -1;
 }
}
int main()
{
 
int key=3;	

 linkedList obj1;
for(int i=0;i<5;i++)
       obj1.insert(i+1);
 cout<<"The linked list is\n";
 obj1.display();
 cout<<"\nThe key is "<<key;
 cout<<bsearchLL(obj1.head,obj1.tail,key,1,obj1.n);
 return 0;
}
