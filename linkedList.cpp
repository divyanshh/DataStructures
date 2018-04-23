#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;	
};

struct dllnode{
	int data;
	dllnode* next;
	dllnode* prev;
};

Node* beginning(Node*);
void middle(Node*);
int length(Node*);
void print(Node*);
void addAtEnd(Node*);
void deleteMiddle(Node*);
void deleteLast(Node*);
Node* deleteFirst(Node*);
Node* swap(Node*);
void convertToCLL(Node*);
void insertIntoCLL(Node*);
void deleteFromCLL(Node*);
void insertIntoDLL(dllnode*);
void deleteFromDLL(dllnode*);
void printdll(dllnode*);

int main() {
	
	int c;
	Node* head = new Node();
	dllnode* dllhead = new dllnode();
	cout <<"enter the value for the first node\n";
	cin >>head->data;
	dllhead->data = head->data;
	dllhead->next = NULL;
	dllhead->prev = NULL;
	head->next = NULL;
	
	for(;;) {
		
	cout <<"1 at beginning \n2 middle of the list \n3at end of the list\n4 to print the list\n5to calculate length\n6 to delete first node\n7 to delete middle node\n";
	cout <<"8 to delete last node\n9 to swap first and last node\n10 to convert list to CLL\n11 insert into CLL\n12 delete from CLL\n";
	cout <<"13 to insert to DLL\n14 to delete from DLL\n15 print dll\n0 to exit\n ";
	cin >>c;
	
	switch(c) {

		case 1:
		head = beginning(head);
		break;
		case 2:
		middle(head);
		break;
		case 3:
		addAtEnd(head);
		break;
		case 4:
		print(head);
		break;
		case 5:
		cout <<length(head);
		case 6:
		head = deleteFirst(head);
		break;
		case 7:
		deleteMiddle(head);
		break;
		case 8:
		deleteLast(head);
		case 9:
		head = swap(head);
		break;
		case 10:
		convertToCLL(head);
		break;
		case 11:
		insertIntoCLL(head);
		break;
		case 12:
		deleteFromCLL(head);
		break;
		case 13:
		insertIntoDLL(dllhead);
		break;
		case 14:
		deleteFromDLL(dllhead);
		break;
		case 15:
		printdll(dllhead);
		break;

	}
	if (c == 0) {
		break;
	}
}

	return 0;

}

Node* beginning(Node* x) {

	Node* temp = new Node();
	cout <<"enter the value for new node";
	cin >>temp->data;
	temp->next = x;
	return temp;

}

void middle(Node* x) {
	int len = length(x);
	int mid;
	if (len%2 == 0) {
		mid = len/2;
	}
	else {
		mid = len/2 +1;
	}
	for(int i = 0;i < mid-1 ;i++) {
		x = x->next;
	}
	Node* temp = new Node();
	cout <<"enter the value for the node";
	cin >>temp->data;
	temp->next= x->next;
	x->next = temp;
	
}

void addAtEnd(Node* x) {
	
	do {
		x = x->next;
	}while(x->next != NULL);
	
	Node* temp = new Node();
	cout <<"enter the value for the node";
	cin >>temp->data;
	x->next = temp;
	temp->next = NULL;
	
}

Node* deleteFirst(Node* x) {
	
	x = x->next;
	return x;
	
}

void deleteLast(Node* x) {
	
	for(int i = 1; i < length(x)-1; i++){
		x = x->next;
	}
	x->next = NULL;
}

void deleteMiddle(Node* x) {
	
	int len = length(x);
	int mid;
	if (len%2 == 0) {
		mid = len/2;
	}
	else {
		mid = len/2 +1;
	}
	for(int i = 0;i < mid-1 ;i++) {
		x = x->next;
	}
	x->next = NULL;
	
}

Node* swap(Node* x) {
	
	Node* tempHead = new Node();
	Node* secondLast = new Node();
	tempHead = x;
	
	for(int i = 1; i < length(x)-1; i++){
		x = x->next;
	}
	secondLast = x;
	x = x->next;
	x->next = tempHead->next;
	secondLast->next = tempHead;
	return x;
}

void convertToCLL(Node* x) {
	
	Node* tempHead = new Node();
	tempHead = x;
	do {
		x = x->next;
	}while(x->next != NULL);
	x->next = tempHead;
	
}

void insertIntoCLL(Node* x) {
	
	Node* temp = new Node();
	Node* add = new Node();
	temp = x;
	do {
		x = x->next;
	}while(x->next != temp);
	
	cout <<"enter the value for the node";
	cin >>add->data;
	x->next = add;
	add->next = temp;
}

void deleteFromCLL(Node* x) {
	
	int pos;
	cout <<"enter posn of node to be deleted";
	cin >>pos;
	for(int i = 1; i < pos-1 ; i++) {
		x = x->next;
	}
	x->next = x->next->next;
	
}

void insertIntoDLL(dllnode* x) {
	
	dllnode* temp = new dllnode();
	
	while(x->next != NULL) {
		x = x->next;
	};
	
	cout <<"enter the value of the node";
	cin >>temp->data;
	x->next = temp;
	temp->prev = x;
	temp->next = NULL;
	
}

void deleteFromDLL(dllnode* x) {
	
	do {
		x = x->next;
	}while(x->next != NULL);
	
	x = x->prev;
	x->next = NULL;
}

int length(Node* y) {
	
	int length = 1;
		
		do {
			y = y->next;
			++length;
			}while(y->next != NULL);
				
	return length;

}

void print(Node* y) {
	do {
		cout << y->data;
		y = y->next;
		}while(y->next != NULL);
		cout << y->data;
	
}

void printdll(dllnode* y) {
	do {
		cout << y->data;
		y = y->next;
		}while(y->next != NULL);
		cout << y->data;
	
}