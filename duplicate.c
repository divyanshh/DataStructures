#include<stdio.h>

void main()
{
	int n, i,j,k;
	printf("enter the length of array\n" );
	scanf("%d",&n);
	int arr[n];

	for (i = 0; i < n; ++i)
	{
		printf("input the %d ith element\n",i+1);
		scanf("%d",&arr[i]);
	}

	for (i = 0; i < n; ++i)
	{
		for (j=(i+1); j < n; ++j)
		{
			if (arr[i]==arr[j])
			{
				for ( k = j; k < n; ++k)
				{
					arr[j]=arr[j+1];
				}
				n--;
			}
		}
	}


	for (i = 0; i < n; ++i)
	{
		printf("%d\n",arr[i]);
	}
}

