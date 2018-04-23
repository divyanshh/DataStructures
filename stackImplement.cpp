#include <iostream>
using namespace std;

struct stackd {
    
    int data[100];
    int top;
    
} st;

void push() {
    
    st.top++;
    int value;
    cout <<"enter the value to push\n";
    cin >> value;
    cout << value;
    st.data[st.top] = value;
    cout << st.top;
    
}

void pop() {
    
    cout<< st.data[st.top];
    st.top--;
    
    
}

int main() {
    
    st.top = -1;
    int c;
    
    for(;;) {
        
        cout <<"enter 1 to push 2 to pop and 0 to exit\n";
        cin >>c;
        
        switch(c) {
                
            case 1:
                push();
                break;
                
            case 2:
                if (st.top == -1) {
                    cout << "stack is empty\n";
                }
                else {
                    pop();
                    break;
                }
                
        }
        
        if(c == 0) {
            break;
        }
    }
}