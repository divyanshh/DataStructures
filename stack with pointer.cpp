#include <iostream>
using namespace std;

struct stackd {
    
    int data[100];
    int top;
    
};



void push(stackd *st) {
    
    int value;
    cout <<"enter the value to push\n";
    cin >> value;
    cout << value;
    st->data[st->top] = value;
    st->top++;
    
}

void pop(stackd* st) {
    
    st->top--;
    cout<< st->data[st->top];
    
    
}

int main() {
    
    stackd *st = new stackd();
    st->top = 0;
    int c;
    
    for(;;) {
        
        cout <<"enter 1 to push 2 to pop and 0 to exit\n";
        cin >>c;
        
        switch(c) {
                
            case 1:
                push(st);
                break;
                
            case 2:
                if (st->top == 0) {
                    cout << "stack is empty\n";
                }
                else {
                    pop(st);
                    break;
                }
                
        }
        
        if(c == 0) {
            break;
        }
    }
}