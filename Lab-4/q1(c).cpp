
#include<iostream>
using namespace std;

int length(int* array) {
	int i;
	for (i=0; *(array+i)!='\0'; ++i) {}

	return i;
}

void initialize(int* array, int size) {
	for (int i=0; i<size; ++i) {
		*(array+i) = '\0';
	}
}

void push(int* array, int x) {
	*(array+length(array)) = x;
}

void pop(int* array) {
	*(array+length(array)-1) = '\0';
}

void display(int* array) {
	for (int i=0; i<length(array); ++i) {
		cout << *(array+i) << endl;
	}
}

int main() {
	int foo[50];
	initialize(foo, 50);

	cout << length(foo) << endl;
	cout << "Enter five values of stack: " << endl;
	int fi=0;
	for (int i=0; i<5; ++i) {
		cin >> fi;
		push(foo, fi);
	}
	pop(foo);
	display(foo);

	return 0;
}	

