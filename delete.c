#include <stdio.h>

void main()
{
	int n,i, num;
	printf("enter the length of array\n" );
	scanf("%d",&n);
	int arr[n];

	for (i = 0; i < n; ++i)
	{
		printf("input the %d ith element\n",i+1);
		scanf("%d",&arr[i]);
	}

	printf("enter position of the element you want to delete\n");
	scanf("%d",&num);

	for (i = num; i < n; ++i)
	{
		arr[i]=arr[i+1];
	}
	n--;
	for (i = 0; i < n; ++i)
	{
		printf("%d\n",arr[i]);
	}

}
