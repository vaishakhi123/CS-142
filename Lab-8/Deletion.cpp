#include <iostream>
using namespace std;
class node		
{
    public:
    int data;
    node *parent,*left,*right;
    node()		
    {
        data=0;
        parent=NULL;
        left=NULL;
        right=NULL;
    }
};
class BST		
{
    public:
    node *root=NULL;		
    int insert(int x)
     {
	node *temp= new node;
	temp->data=x;
	temp->parent=temp->left=temp->right=NULL;
	node *curr=new node;
	curr= root;
	if(root==NULL)
	{
	  root=temp;
	}
	else
	{
	  while(1)
	  {
	    if(x<curr->data)
	    {
	       if(curr->left==NULL)
	       {
	         temp->parent=curr;
	         curr->left=temp;
	         break;
	       }
	       else
                   {
	         curr=curr->left;
	       }
	    }
	    else if(x>curr->data)
	    {
	      if(curr->right==NULL)
	      {
	         temp->parent=curr;
	         curr->right=temp;
	         break;
	      }
	      else
      	      {
	         curr=curr->right;
	      }
	    }
             }
             return 0;
          }
      }
    void del(int key)
    {
        node *p=bsearch(root,key);
        if(p->left == NULL && p->right == NULL)
        {
            if(p->parent->left == p)
            p->parent->left=NULL;
            else
            p->parent->right=NULL;
            delete p;
        }
        else if(p->left == NULL || p->right == NULL)
        {
            if(p==root)
            {
   	            if(p->left!=NULL)
   	            root=p->left;
   	            else
   	            root=p->right;
            }
            else
            {
                if(p->left == NULL)
                {
                    if(p->parent->left == p)
                    p->parent->left=p->right;
                    else
                    p->parent->right=p->right;
                    delete p;
                }
                else 
                {
                    if(p->parent->left == p)
                    p->parent->left=p->left;
                    else
                    p->parent->right=p->left;
                    delete p;
                }
            }
        }
        else
        {
            node *temp=p->left;
            if(temp==NULL)
            while(temp->right != NULL)
            {
                temp=temp->right;
            }
            if(temp->left != NULL)
            {
                p->data=temp->data;
                if(temp->parent->left == temp)
                temp->parent->left=temp->left;
                else
                temp->parent->right=temp->left;
                delete temp;
            }
            else
            {
                p->data=temp->data;
                if(temp->parent->left == temp)
                {
                    temp->parent->left=NULL;
                    delete temp->parent->left;
                }
                else
                {
	                temp->parent->right=NULL;
	                delete temp->parent->right;
                }
            }
        }
    }
    node *bsearch(node *v,int data)
    {
        node *temp=v,*p;
        if(v==NULL)
        {
            cout<<"Not Found\n";
            return NULL;
        }
        else
        {
            if(data < temp->data)
            p=bsearch(temp->left,data);
            else if(data > temp->data)
            p=bsearch(temp->right,data);
            else
            {
                cout<<"Found\n";
                return temp;
            }
            return p;
        }
    }
    void display(node *v)
    {
        if(v==NULL)
        return;
        display(v->left);
        cout<<v->data<<" ";
        display(v->right);
    }
};
int main()
{
    BST bst;
    int n,data;
    cout<<"Enter the number of entries"<<endl;
    cin>>n;
    cout<<"Enter data"<<endl;
    for(int i=1;i<=n;i++)
    {
        
        cin>>data;
        bst.insert(data);
    }
    bst.display(bst.root);
    cout<<"\n";
    cout<<"Enter the data you want to search\n";
    cin>>data;
    bst.bsearch(bst.root,data);
    cout<<"Enter the data you want to delete\n";
    cin>>data;
    bst.del(data);
    cout<<"Tree after deletion"<<endl;
    bst.display(bst.root);
    
    return 0;
}

