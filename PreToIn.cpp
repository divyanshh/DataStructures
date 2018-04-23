#include <bits/stdc++.h>
using namespace std;

bool isAlpha(char ch)
{
	if( ch >= 'a' && ch <= 'z' )
		return true;
	if( ch>= 'A' && ch <= 'Z' )
		return true;

	return false;
}

int main()
{
	string s;

	char stack[100];
	int top = 0;

	cout<< "Enter the PREFIX Expression that you want to convert: ";
	cin>> s;

	for(int i=s.length()-1; i>=0; i--)
	{
		if( isAlpha(s[i]) || ( s[i] >= '0' && s[i] <= '9' ) )
			stack[top++] = s[i];

		else
		{
			if( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' )
			{
				if( isAlpha(stack[top]) && isAlpha(stack[top-1]) )
				{
					char ch1, ch2;

					ch1 = stack[top-1];
					ch2 = stack[top];

					stack[top-1] = '(';
					stack[top] = ch1;
					stack[top+1] = s[i];
					stack[top+2] = ch2;
					stack[top+3] = ')';

					top = top+3;
				}
				else
				{
					string s1, s2;
					while( stack[top] != '(' )
					{
						s1 += stack[top--];
					}
					s1 += stack[top--];


				}
			}
		}
	}

	return 0;
}