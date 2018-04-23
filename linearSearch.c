

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

   printf("Enter the number to num\n");
   scanf("%d", &num);
 
   for (i = 0; i < n; i++)
   {
      if (arr[i] == num)    
      {
         printf("%d is present at location %d.\n", num, i+1);
         break;
      }
   }
   if (i == n)
      printf("%d is not present in array.\n", num);
 
}
