#include <stdio.h>

void main()
{
	int n,i, num,last,mid,first;
	printf("enter the length of array\n" );
	scanf("%d",&n);
	int arr[n];

	for (i = 0; i < n; ++i)
	{
		printf("input the %d ith element\n",i+1);
		scanf("%d",&arr[i]);
	}

	printf("enter the number you want to search");
	scanf("%d",num);

	first=0;
	last=n-1;
	mid=(first+last)/2;

	
	while(first<=last)
	{
		if(arr[mid]<num)
		{
			first=mid+1;
		}

		else if(arr[mid]=num)
		{
			printf("number is at %d position",mid+1);
		}

		else
		{
			last=mid-1;
		}
		mid=(first+last)/2;
	}
	if(first > last)
	{
		printf("Not found! %d is not present in the list.",num);
	}

}