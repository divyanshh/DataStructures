#include<iostream>
using namespace std;


struct que
{
    int value;
    que *next;
} *np=NULL, *front=NULL, *rear=NULL , *rear2 =NULL , *front2=NULL ;



/*void push_circular(int x)
{
    np= new que;
    np->value=x;
    if (front== NULL)
    {
        front =rear=np;
        rear->next=front;
    }

    else
    {
        rear->next=np;
        np->next=front;
        front=rear=np;
    }
}*/

void display()
{
	np=new que;
	np=front;
	while(np!=NULL)
	{
		cout<<np->value<<endl;
		np=np->next;
	}
}
void push(int x  )
{ 
    np = new que;
    np->value = x;
    np->next = NULL;
    if(front == NULL)
    {
        front = rear = np;
        rear->next = NULL;
    }
    else
    {
        rear->next = np;
        rear = np;
        rear->next = NULL;
    }
}
void del()
{
    if(front==NULL)
    cout<<"queue is underflowed\n";

    else
    {
    	front=front->next;	
    }
    
}

void count()
{
	int i=0;
	np=front;
    while(np) {
        np=np->next;
        ++i;
    }
    cout<<i<<endl;
}

void reverse()
{
	np=new que;
	np=front;
	int i,j,flag=0;
	int arr[100];
	while(np)
	{
		arr[i]=np->value;
		np=np->next;
		++i;
	}
	front=rear=NULL;
	for(j=0;j<=i;++j)
	{
		push(arr[i-j] );
	}
	np=front;
	i=0;
	while(np)
	{
	if(!(np->value==arr[i]))
	{
		flag=1;
	}
	np=np->next;
	++i;
	}
	
	if(flag==0)
	{
		cout<<"maa chudao";
	}
	
}
int main()
{ 
    int x,a;
    while(1)
{

cout<<"1)insert  2)delete  3)count \n";
cin>>x;
switch(x)
{
    case 1:
    cout<<"enter the number you want to insert \n";
    cin>>a;
    push(a);
    break;

    case 2:
    del();
    break;

    case 3:
    count();
    break;
    
    case 4:
    display();
    break;
    
    case 5:
    reverse();
    break;
    
    
}
}
     return 0;       
}
