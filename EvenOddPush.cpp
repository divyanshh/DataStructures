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

void display(node* root)
{
	while( root != NULL )
	{
		cout<< root->data<< "\n";
		root = root->next;
	}
}

int main()
{
	int n;

	cout<< "Enter the no. of elements you want to add : ";
	cin>> n;

	int arr[n], i;
	for(i=0; i<n; i++)
		cin>> arr[i];


	node* even = new node();
	node* odd = new node();

	for(i=0; i<n; i++)
	{
		if( arr[i]%2 == 0 )
			insert(even, arr[i]);
		else
			insert(odd, arr[i]);
	}

	cout<< "Linked List containing Even Elements: \n";
	display(even->next);

	cout<< "Linked List containing Odd Elements: \n";
	display(odd->next);

	return 0;
}