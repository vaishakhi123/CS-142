#include <iostream>
#include <string.h>
using namespace std;
class Issue		//tells the compiler what an issue is
{
 public:
 char name[20], desc[100];
 long int ph;
 Issue *next;
};
class Service
{
 private:
 Issue *head,*tail;		//points to the first and last node
 public:
 Service()		//constructor to initialize head and tail
 {
  head=NULL;
  tail=NULL;	
 }	
 void addIssue(char nm[],long int p,char des[])		//adds issue to the list
 {
  Issue *temp=new Issue;
  strcpy(temp->name,nm);
  strcpy(temp->desc,des);
  temp->ph=p;
  if(head==NULL)		//checking if the list is empty
  {
   head=temp;
   tail=temp;
  }
  else
  {
   if(chkPal(temp->name)==1)		//if the name is a palindrome
   {
   	temp->next=head;
   	head=temp;
   }
   else
   {
    tail->next=temp;
    tail=temp;
   }
  }
 }
 int chkPal(char nm[])		//checks if the name is a palindrome
 {
  int j=0;	
  char rev[20];
  for(int i=strlen(nm)-1;i>=0;i--)
  {
   rev[j]=nm[i];	
   j++;	
  }
  if(strcmp(nm,rev)==0)
  return 1;
  else
  return 0;
 }
 void displayIssue()		//displays the list
 {
  Issue *temp=head;
  while(temp!=NULL)
  {
   cout<<temp->name<<" "<<temp->desc<<" "<<temp->ph<<"\n";
   temp=temp->next;
  }
  cout<<"\n\n\n";
 }
};
int main()
{
 //object creation and functions calling
 Service entry;
 entry.displayIssue();
 entry.addIssue("ISSUE",9861856611,"Testing code");
 entry.displayIssue();
 entry.addIssue("ISSI",8895033341,"Code Testing");
 entry.displayIssue();
 entry.addIssue("ISS",9090955556,"PALINDROME STACK");
 entry.displayIssue();
 entry.addIssue("PRBLM",9114772624,"STACK PALINDROME");
 entry.displayIssue();
 entry.addIssue("PRORP",8093316657,"CODE SUCCESFUL");
 entry.displayIssue();
 entry.addIssue("PROB",9778964166,"SUCCESSFUL CODE");
 entry.displayIssue();
 entry.addIssue("TICKET",9861861442,"PDSL 2");
 entry.displayIssue();
 entry.addIssue("TICIT",7377376656,"2 PDSL");
 entry.displayIssue();
 entry.addIssue("TIIT",9040045884,"LAST ONE");
 entry.displayIssue();
 entry.addIssue("ENDNE",9667723421,"ONE LAST");
 entry.displayIssue();
 return 0;   	
}
