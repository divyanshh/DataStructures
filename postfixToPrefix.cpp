#include <iostream>
using namespace std;

struct stackd{
    
    string data[100];
    int top;
    
} st;

void push(string ch) {
    
    st.top++;
    st.data[st.top] = ch;
    
}

string pop() {
    
    string c = st.data[st.top];
    st.top--;
    return c;
    
}

int main() {
    
    st.top = -1;
    string s;
    string c;
    cout << "enter the postfix expression\n"; // input 42$3*3-84/11+/+
    cin >> s;								  // output +-*$4233//84+11
    for(int i = 0; i < s.length(); i++) {
        
        
        if(s[i] == '^' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '$') {
            
            string a = pop();
            string b = pop();
            string temp(1,s[i]);
            c = "";
            c.append(temp);
            c.append(b);
            c.append(a);
            push(c);
            
        }
        
        else {
            
            string temp(1,s[i]);
            push(temp);
        }
        
    }
    
    cout <<c;
}