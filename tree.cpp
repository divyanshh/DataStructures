#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right; 
};

node *getnode(int data)
{
	node *newnode =new node();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
};

main()
{
	node *root= getnode(12);
	root->left= getnode(10);
	root->right= getnode(18);
	root->right->right=getnode(21);
}

int deleteall(node *temp)
{
	if(temp==NULL)
		return;
	if (temp->left!=NULL)
	{
		cout<<temp->left;
		deleteall(temp->left)
	}
	if (temp->right!=NULL)
	{
		cout<<temp->right;
		deleteall(temp->right);
	}
	free(temp)
	return;
}

int depth(node *temp)
{
	int depthl,depthr=0;
	if(temp==NULL)
		return;
	if (temp->left!=NULL)
	{
		depthl=depth(temp->left);
	}
	if (temp->right!=NULL)
	{
		depthr=depth(temp->right);
	}

	if (depthl>depthr)
	{
		depthl++;
	}
	else
		depthr++;
	return;
}


