#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

void insert(node* root, int data)
{
	if( root == NULL )
	{
		root->data = data;
		root->next = NULL;
		return;
	}

	while( root->next != NULL )
		root = root->next;

	node* temp = new node();
	temp->data = data;
	temp->next = NULL;

	root->next = temp;
}

void deleteNode(node* root)
{
	if( root->next == NULL )
	{
		cout<< "Empty Linked List \n";
		return;
	}

	while( (root->next)->next != NULL )
		root = root->next;

	node* temp = new node();
	temp = root->next;

	cout<< "Element to be deleted: "<< temp->data;
	root->next = NULL;
	delete(temp);
}

void display(node* root)
{
	while( root != NULL )
	{
		cout<< root->data<< "\n";
		root = root->next;
	}
}

void top(node* root)
{
	while( root->next != NULL )
		root = root->next;

	cout<< "The top element is: "<< root->data;
}

int main()
{
	node* root = new node();
	int choice, data;

	while( true )
	{
		cout<< " 1. Push\n 2. Pop\n 3. Display\n 4.Top\n 5. Exit : ";
		cin>> choice;

		if( choice == 5 )
			break;

		if( choice == 1 )
		{
			cout<< "Enter the element that you want to insert: ";
			cin>> data;

			insert(root, data);
		}
		else if( choice == 2 )
		{
			deleteNode(root);
		}
		else if( choice == 3 )
		{
			display(root->next);
		}
		else if( choice == 4 )
		{
			top(root->next);
		}
		else
			cout<< "Not a valid choice.\n";
	} 

	return 0;
}