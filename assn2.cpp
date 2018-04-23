#include <iostream>
using namespace std;

void upperOrLower(int* , int);
void printMatrix(int* , int);
void magicSquare(int* , int);
void trace(int* , int);
void symmetric(int* , int);
void sparse(int* , int);
void saddlePoint(int* , int);

int main() {
	
	int ch;
	int val;
	cout <<"enter the value for square matrix\n";
	cin >>val;
	int matrix[val][val];
	cout<<"enter the matrix\n";
	for(int i = 0; i < val; i++) {
		for(int j = 0; j < val; j++) {
			cout <<"enter " <<i+1<< " " <<j+1<< " element\n";
			cin >> matrix[i][j];
		}
	}
	int* add = &matrix[0][0];
	
	for(;;) {
		
		cout <<"1 to show whether the matrix is upper triangular or lower triangular or neither of the two.\n";
		cout <<"2 to determine whether or not the given square matrix is magic square.\n";
		cout <<"3 to find the trace of a square matrix.\n";
		cout <<"4 to determine whether or not the given matrix is symmetric.\n";
		cout <<"5 to add and subtract two sparse matrices.\n";
		cout <<"6 to determine the saddle point if exist in the given matrix.\n";
		cout <<"7 to print matrix.\n";
		cout <<"0 to exit.\n";
		
		cin >>ch;
		
		switch(ch) {
			
			case 1:
			upperOrLower(add , val);
			break;
			case 2:
			magicSquare(add , val);
			break;
			case 3:
			trace(add , val);
			break;
			case 4:
			symmetric(add , val);
			break;
			case 5:
			sparse(add , val);
			break;
			case 6:
			saddlePoint(add , val);
			break;
			case 7:
			printMatrix(add , val);
			
		}
		if (ch == 0) {
			break;
		}
		
	}
	return 0;
}

void upperOrLower(int* mat , int v) {
	int u = 0 ,l = 0;
	
	for( int i = 1; i <= v; i++ ) {
		
		for( int j = 1; j <= v; j++ ) {
			
			if(i>j && *mat == 0) {
				++u;
			}
			if(j>i && *mat == 0) {
				++l;
			}
			mat++;
			
		}
	}
	
	int n = 0;
	while(v != 0) {
		n = n + (--v);
	};
	
	if(u == n) {
		cout <<"upper triangular matrix\n";
	}
	else if(l == n) {
		cout <<"lower triangular matrix\n";
	}
	else {
		cout <<"neither upper nor lower triangular matrix\n";
	}
	
}

void magicSquare(int* mat , int v) {
	
	int sum = (v*((v*v)+1))/2;
	int conditionsSatisfied = 0;  //2n+2 conditions
	int s = 0;
	
	for( int i = 1; i <= v; i++ ) {
			
			for( int j = 1; j <= v; j++ ) {
				
				s = s + *mat; 
				mat++;
			}
			if(s == sum) {
				conditionsSatisfied++;
			}
			s = 0;
		}
		
		for( int i = 1; i <= v; i++ ) {
				for( int j = 1; j <= v; j++ ) {
					
					s = s + *mat;
					mat = mat + v;
			
				}
				if(s == sum) {
				conditionsSatisfied++;
			}
			s = 0;
			mat = mat - (v*v) + 1;
			}
			
			for( int i = 1; i <= v; i++ ) {
				for( int j = 1; j <= v; j++ ) {
					
					if(i == j) {
						s = s + *mat;
					}
					++mat;
			
				}
			}
			if(s == sum) {
			conditionsSatisfied++;
			s = 0;
			
			
		
	}
}

void trace(int* mat , int v) {
	int m[v][v];
	int s = 0;
	
	for( int i = 1; i <= v; i++ ) {
		for( int j = 1; j <= v; j++ ) {
			m[i][j] = *mat;
			mat++;
			
		}
	}
	
	for( int i = 1; i <= v; i++ ) {
		for( int j = 1; j <= v; j++ ) {
			
			if(i == j) {
				s = s + m[i][j];
			}
	
		}
	}
	cout <<"sum of main diagonal = "<<s<<"\n";
	
}

void symmetric(int* mat , int v) {
	
	int m[v][v];
	int s[v][v];
	int c = 0;	
	
	for( int i = 0; i < v; i++ ) {
		for( int j = 0; j < v; j++ ) {
			m[i][j] = *mat;
			mat++;
			
		}
	}
	
	for( int i = 0; i < v; i++ ) {
		for( int j = 0; j < v; j++ ) {
			s[j][i] = m[i][j];
			
		}
	}
	
	for( int i = 1; i <= v; i++ ) {
		for( int j = 1; j <= v; j++ ) {
			
			if (s[i][j] == m[i][j]) {
				c++;
			} 
			
		}
	}
	
	if(c == (v*v)) {
		cout << "symmetric\n";
	}
	else {
		cout << "not symmetric\n";
	}
	
}

void sparse(int* mat , int v) {
	
	int zeroes = 0;
	int nonzeroes = 0;
	
	for( int i = 1; i <= v; i++ ) {
		for( int j = 1; j <= v; j++ ) {
			if(*mat == 0) {
				zeroes++;
			}
			else {
				nonzeroes++;
			}
			mat++;
			
		}
	}
	
	if(zeroes >= nonzeroes) {
		cout << "sparse matrix\n";
	}
	else {
		cout << "dense matrix\n";
	}
	
}

void saddlePoint(int* mat , int v) {
	
	int m[v][v];
	int e,c = 0;
	
	for( int i = 0; i < v; i++ ) {
		for( int j = 0; j < v; j++ ) {
			m[i][j] = *mat;
			mat++;
			
		}
	}
	
	for( int i = 0; i < v; i++ ) {
		for( int j = 0; j < v; j++ ) {
			c = 0;
			e = m[i][j];
			
			for(int z = 0; z < v; z++) {
				if (e > m[z][j]) {
					++c;
				}
			}
			
			if(c == (v-1)) {
				for(int k = 0; k < v; k++) {
					if(e < m[i][k]) {
						++c;
					}
				}
			}
			
			if(c == ((2*v)-2)) {
				cout <<"saddle point = "<<e<<" at position "<<i+1<<" "<<j+1<<"\n";
			}
			
			
		}
		
	}
	
}

void printMatrix(int* mat , int v) {
	for( int i = 0; i < v; i++ ) {
		for( int j = 0; j < v; j++ ) {
			cout << *mat;
			mat++;
			
		}
		cout<<"\n";
	}
	cout <<"\n";
}