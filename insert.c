#include <stdio.h>

void main()
{
	int n,i, num,pos,temp;
	printf("enter the length of array\n" );
	scanf("%d",&n);
	int arr[30];

	for (i = 0; i < n; ++i)
	{
		printf("input the %d ith element\n",i+1);
		scanf("%d",&arr[i]);
	}

	printf("enter number and position you want number to insert to\n");
	scanf("%d %d",&num,&pos);

	for (i=n; i>(pos-2);--i)
	{
		arr[i+1]=arr[i];
	}
	arr[pos-1]=num;
	n++;
	for (i = 0; i < n; ++i)
	{
		printf("%d\n",arr[i]);
	}

}
