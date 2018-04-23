//Bubble sort
#include <iostream>
using namespace std;

int main() {
	
	int n;
	cout<< "enter no of elements\n";
	cin >> n;
	int array[n];
	int temp;
	
	cout <<"enter the elements\n";
	
	for(int i = 0; i < n; i++ ) {
		cout<< "enter "<<i+1<<" element\n";
		cin >> array[i];
		
	}
	
	for(int i = 0; i < n; i++) {
		
		for(int j = 0; j < n-i-1; j++) {
			
			if (array[j] > array [j+1]) {
				
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				
			} 
		}
	}
	
	for(int i = 0; i < n; i++ ) {
		cout<< array[i];
		
	}
	
}