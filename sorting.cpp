//sorting
#include <iostream>
using namespace std;

struct arr {
    
    int data[100];
    int size;
    
} ar;

void insertionSort() {
    
    int n = ar.size;
    int temp;
    int hole;
    for(int i = 0 ; i < n-1 ; i++) {
        
        hole = i+1;
        int value = ar.data[hole];
        
        while((hole != 0)  && (ar.data[hole-1] > ar.data[hole])) {
            
            temp = ar.data[hole-1];
            ar.data[hole-1] = ar.data[hole];
            ar.data[hole] = temp;
            hole = hole-1;
            
        }
        
        for(int i = 0 ; i < n ; i++ ) {
            cout<< ar.data[i];
            
        }
        
        cout<<"\n";
    }
    
    cout<<"sorted array = ";
    for(int i = 0 ; i < n ; i++ ) {
        cout<< ar.data[i];
        
    }
    
    cout<<"\n";
    
}

void selectionSort() {
    
    int n = ar.size;
    int min;
    int posn;
    int c = 0;
    for(int i = 0 ; i < n ; i++) {
        
        min = ar.data[i];
        for(int j = i ; j < n-1 ; j++) {
            
            if(ar.data[j+1] < min) {
                min = ar.data[j+1];
                posn = j+1;
                c = 1;
            }
        }
        
        if(c == 1) {
            ar.data[posn] = ar.data[i];
            ar.data[i] = min;
            c = 0;
        }
        
    }
    
    for(int i = 0 ; i < n ; i++ ) {
        cout<< ar.data[i];
        
    }
    
    cout<<"\n";
}

void bubbleSort() {
    
    int temp;
    int n = ar.size;
    for(int i = 0; i < n; i++) {
        
        for(int j = 0; j < n-i-1; j++) {
            
            if (ar.data[j] > ar.data[j+1]) {
                
                temp = ar.data[j];
                ar.data[j] = ar.data[j+1];
                ar.data[j+1] = temp;
                
            }
            
            for(int i = 0 ; i < n ; i++ ) {
                cout<< ar.data[i];
                
            }
            
            cout<<"\n";
        }
    }
    
    cout<<"sorted array = ";
    for(int i = 0 ; i < n ; i++ ) {
        cout<< ar.data[i];
        
    }
    
    cout<<"\n";
}

void merge(int *l , int nL , int *r , int nR , int *A){
    
    int i = 0 , j = 0 , k = 0;
    
    while(i < nL && j < nR) {
        
        if(l[i] <= r[j]) {
            
            A[k] = l[i];
            k++;
            i++;
        }
        else{
            
            A[k] = r[j];
            j++;
            i++;
        }
    }
    
    while(i < nL) {
        
        A[k] = l[i];
        k++;
        i++;
    }
    
    while(j < nR) {
        
        A[k] = r[j];
        k++;
        j++;
    }
}


void mergeSort(int *A , int n) {
    
    if(n < 2) {
        
        return;
    }
    else {
        
        int mid = n / 2;
        int left[mid];
        int right[(n - mid)];
        
        for(int i = 0 ; i < mid ; i++) {
            
            left[i] = A[i];
        }
        
        for(int i = mid ; i < n ; i++) {
            
            right[i-mid] = A[i];
        }
        
        mergeSort(left , mid);
        mergeSort(right , n - mid);
        
        merge(left , mid , right , n - mid , A);
        
    }
}

int partitionForQS(int *A , int p , int r) {
    
    int pivot = A[r];
    int pIndex = p;
    int temp;
    
    for(int i = p ; i <= r ; i++) {
        
        if(A[i] < pivot) {
            
            temp = A[i];
            A[i] = A[pIndex];
            A[pIndex] = temp;
            pIndex = pIndex + 1;
            
        }
        
    }
    
    temp = A[pIndex];
    A[pIndex] = A[r];
    A[r] = temp;
    cout<<"pivot = "<<A[pIndex]<<" at posn = "<<pIndex+1<<"\n";
    
    for(int i = 0 ; i < ar.size ; i++ ) {
        cout<< ar.data[i];
        
    }
    
    cout<<"\n";
    
    return pIndex;
}

void quickSort(int *array , int p , int r) {
    
    if(p < r) {
        
        int q = partitionForQS(array , p , r);
        quickSort(array , p , q-1);
        quickSort(array , q+1 , r);
    }
}

void shellSort() {
    
    
}

void radixSort() {
    
    
}

void countingSort() {
	
	
}

int main() {
    
    int ch;
    
    cout<<"enter the size of array\n";
    cin >> ar.size;
    
    for(int i = 0 ; i < ar.size ; i++) {
        
        cout << "enter " << i+1 << " element\n";
        cin >> ar.data[i];
    }
    
    for(;;) {
        
        cout<<"enter the type of sorting to run\n";
        cout<<"1-insertion sort\n";
        cout<<"2-selection sort\n";
        cout<<"3-bubble sort\n";
        cout<<"4-merge sort\n";
        cout<<"5-quick sort\n";
        cout<<"6-Shell sort\n";
        cout<<"7-Radix sort\n";
        cout<<"8-Counting sort\n";
		cout<<"0-exit\n";
        
        cin >> ch;
        
        switch(ch) {
                
            case 1:
                insertionSort();
                break;
                
            case 2:
                selectionSort();
                break;
                
            case 3:
                bubbleSort();
                break;
                
            case 4:
                mergeSort(ar.data , ar.size);
                
                for(int i = 0 ; i < ar.size ; i++ ) {
                    cout<< ar.data[i];
                    
                }
                
                cout<<"\n";
                break;
                
            case 5:
                
                quickSort(ar.data , 0 , ar.size-1);
                
                cout<<"sorted array = ";
                for(int i = 0 ; i < ar.size ; i++ ) {
                    cout<< ar.data[i];
                    
                }
                
                cout<<"\n";
                break;
                
            case 6:
                shellSort();
                break;
                
            case 7:
                radixSort();
                break;
				
			case 8:
				countingSort();
				break;
        }
        
        if (ch == 0) {
            break;
        }
        
    }
    
}