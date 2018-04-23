#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;

	char stack[100];
	stack[0] = '(';
	int top = 0;

	cout<< "Enter the INFIX Expression that you want to convert: ";
	cin>> s;

	cout<< "The POSTFIX Expression is: ";
	for(int i=0; i<s.length(); i++)
	{
		//cout<< "\n Stack : "<< stack<< endl;
		if( ( s[i] >= 'a' && s[i] <= 'z' ) || ( s[i] >= 'A' && s[i] <= 'Z' ) || ( s[i] >= '0' && s[i] <= '9' ) )
			cout<< s[i];

		else
		{
			if( s[i] == ')' )
			{
				while( stack[top] != '(' )
				{
					cout<< stack[top--];
				}
				top--;
				//stack.erase(top);
			}

			else
			{
				if( s[i] == '+' || s[i] == '-' )
				{
					//cout<< top<< " yo "<< stack[top];
					while( stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/' || stack[top] == '^' )
					{
						cout<< stack[top--];
					}
					//stack.erase(top);
				}

				else if( s[i] == '*' || s[i] == '/' )
				{
					while( stack[top] == '^' || stack[top] == '*' || stack[top] == '/' )
					{
						cout<< stack[top--];
					}
					//stack.erase(top);
				}

				else if( s[i] == '^' )
				{
					while( stack[top] == '^' )
					{
						cout<< stack[top--];
					}
					//stack.erase(top);
				}

				stack[++top] = s[i];
			}
		}
	}	

	return 0;
}