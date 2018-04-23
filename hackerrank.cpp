#include<iostream>
using namespace std;

bool isspiral(long int array[],long int len) {
    long int count = 0;
    for(long int j=0; j<(len/2); j++) {
        
        if((array[j] <= array[len-(j+1)]) && (array[len-(j+1)] <= array[j+1])){
            count++;
        }
        else{
            return false;
        }
        
    }
    
    if(count)
    return true;
}

int main() {
    long int n;
    cin>>n;
    long int arr[n];
    
    for(long int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    if(isspiral(arr , n)){
        cout<<"yes";
    }
    else {
        cout<<"no";
    }
    
}