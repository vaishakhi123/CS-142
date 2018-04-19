#include<iostream>
using namespace std;

void heapify(int arr[],int i,int n);
void heapsort(int arr[],int n);
void print(int arr[],int n);
void swap(int *a,int *b);
int main(){
	int arr[]= {20,25,43,21,79,62};
	int n=sizeof(arr)/sizeof(arr[0]);
	heapsort(arr,n);
	cout<<"The sorted array is: "<<endl;
	print(arr,n);
}
 
void heapify(int arr[],int i,int n){
	int large=i;
	int lc=2*i+1;
	int rc=2*i+2;
	if(lc<n && arr[lc]>arr[large])
	{
		large=lc;
		
	}
	if(rc<n && arr[rc]>arr[large])
	{	
		large=rc;	
	}
	if(large!=i)
	{
		swap(&arr[i],&arr[large]);
		heapify(arr,large,n);

	}
	
}
void heapsort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,i,n);
	cout<<"The maxHeap is "<<endl;
	print(arr,n);	
	for(int i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,0,i);
	}		


}
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
