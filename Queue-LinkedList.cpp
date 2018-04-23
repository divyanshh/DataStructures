#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* insert(node* r, int data)
{
	if( r == NULL )
	{
		r->data = data;
		r->next = NULL;

		return r;
	}

	node* temp = new node();
	temp->data = data;
	temp->next = NULL;

	r->next = temp;

	return r->next;
}

node* deleteNode(node* f, node* r)
{
	if( f == r )
		return NULL;

	node* temp = new node();
	temp = f;

	f = f->next;
	temp->next = NULL;

	delete(temp);
	return f;
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
	node* f = new node();
	node* r = new node();
	int choice, data;

	while( true )
	{
		cout<< " 1. Enqueue\n 2. Dequeue\n 3. Front\n 4. Rear\n 5. Display\n 6. Exit : ";
		cin>> choice;

		if( choice == 6 )
			break;

		if( choice == 1 )
		{
			cout<< "Enter the value you want to insert into Queue: ";
			cin>> data;
			
			r = insert(r, data);
			if( f == NULL )
				f = r;
		}
		else if( choice == 2 )
		{
			f = deleteNode(f, r);
			if( f == NULL )
				r = f;
		}
		else if( choice == 3 )
		{
			cout<< "The element at Front End is: "<< f->data<< "\n";
		}
		else if( choice == 4 )
		{
			cout<< "The element at Rear End is: "<< r->data<< "\n";
		}
		else if( choice == 5 )
			display(f);
		else
			cout<< "Invalid Choice \n";
	}

	return 0;
}