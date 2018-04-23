#include <iostream>
using namespace std;

struct stackd {
    
    char data[100];
    int top;
    
} st;

void push(char ch) {
    
    st.top++;
    st.data[st.top] = ch;
    
}

char pop() {
    
    char c =  st.data[st.top];
    st.top--;
    return c;
    
}

int main() {
    
    st.top = -1;
    string s;
    cout <<"enter the infix expression\n";  //input (A+B/C*(D+E)-F)
    cin >>s;								//output A B C / D E + * + F -
    
    for(int i = 0 ; i < s.length(); i++ ) {
        
        if(isalnum(s[i])) {
            cout << s[i];
        }
        
        else {
            
            if(st.top == -1) {
                push(s[i]);
            }
            
            else {
                
                if(s[i] == '^') {
                    
                    while(st.data[st.top] == '^') {
                        cout<< pop();
                    }
					
					push(s[i]);
                }
                
                
                else if(s[i] == '/' || s[i] == '*') {
                    
                    while(st.data[st.top] == '^' || st.data[st.top] == '*' || st.data[st.top] == '/') {
                        cout << pop();
                    }
					
					push(s[i]);
                }
                
                else if(s[i] == '+' || s[i] == '-' ) {
                    
                    while(st.data[st.top] == '^'|| st.data[st.top] == '*' || st.data[st.top] == '/' || st.data[st.top] == '+' || st.data[st.top] == '-') {
                        cout << pop();
                    }
					
					push(s[i]);
                }
                
                else if(s[i] == ')') {
                    while(st.data[st.top] != '(') {
                        cout << pop();
                    }
                    pop();
                }
				
				else if(s[i] == '(') {
					push(s[i]);
				}
                
                
            }
            
        }
        
    }
	cout<<"\n";
    
}