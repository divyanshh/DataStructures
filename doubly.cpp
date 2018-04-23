//Doubly linked list
#include <iostream>
using namespace std;

struct Node {
	
	int data;
	Node* next;
	Node* prev;

};

Node* firstElement(Node* h) {
	
	Node* temp = new Node();
	
	
		cout<<"enter the value\n";
		cin >> temp->data;
		temp->next = h;
		h->prev = temp;
		temp->prev = NULL;
		
	
	return temp;
	
}

void otherPosn(Node* h) {
	
	int posn;
	cout <<"enter the position\n";
	cin >> posn;
	
	for(int i = 1; i < posn; i++) {
		
		h = h->next;
		
	}
	
	Node* temp = new Node();
	cout<<"enter the data";
	cin>>temp->data;
	temp->next = h;
	temp->prev = h->prev;
	h->prev = temp;
	temp->prev->next = temp;
	
} 

void printList(Node* h) {
	
	while(h->next != NULL) {
		
		cout<<h->data;
		h = h->next;
	}
}

int main() {
	
	int c;
	Node* head = new Node();
	head->next = NULL;
	head->prev = NULL;

	cout<< "enter value for head";
	cin>>head->data;
	
	for(;;) {
	cout<<"1 for 1st element\n";
	cout<<"2 for entering at a position\n";
	cout<<"3 to exit\n";
	cout<<"4 to print list";
	cin >> c;
	
	switch(c) {
		
		case 1:
		head =  firstElement(head);
		break;
		
		case 2:
		otherPosn(head);
		break;
		
		case 4:
		printList(head);
		break;
		
		}
		
		
	
	if(c == 3) {
		break;
	}
}
	
}

