#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[5], f = -1, r = -1, choice, data;

	while( true )
	{
		cout<< " 1. Enqueue\n 2. Dequeue\n 3. Front\n 4. Rear\n 5. Exit : ";
		cin>> choice;

		if( choice == 5 )
			break;

		if( choice == 1 )
		{
			cout<< "Enter the element you want to insert: ";
			cin>> data;

			if( f == -1 )
			{
				f = r = 0;
				arr[r] = data;
			}

			else if( (r+1)%5 != f )
				arr[ (++r)%5 ] = data;
			else
				cout<< "Queue is full or overflow condition \n";
		}
		else if( choice == 2 )
		{
			if( f == -1 )
				cout<< "Queue is Empty or underflow condition \n";

			else
			{
				cout<< "Element to be deleted: "<< arr[f]<< "\n";

				if( f == r )
					f = r = -1;
				else
					f++;
			}
		}
		else if( choice == 3 )
		{
			if( f == -1 )
				cout<< "Queue is Empty or underflow condition \n";

			else
				cout<< "The front element is: "<< arr[f]<< "\n";
		}
		else if( choice == 4 )
		{
			if( f == -1 )
				cout<< "Queue is Empty or underflow condition \n";

			else
				cout<< "The rear element is: "<< arr[r]<< "\n";
		}
		else
			cout<< "Invalid Choice \n";
	}

	return 0;
}