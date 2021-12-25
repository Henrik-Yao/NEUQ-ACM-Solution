#include<iostream>
#include<stack>
using namespace std;
stack<char>ST;
int main()
{
	string S;
	cin >> S;
	int length = S.length(), i;
	for (i = 0; i < length; i++)
	{
		if (S[i] == '(') ST.push(')');
		else if (S[i] == '[') ST.push(']');
		else if (S[i] == '{') ST.push('}');
		else if (S[i] == ')')
		{
			if (ST.top() != S[i])
			{
				cout << "no" << endl;
				break;
			}
			else
			{
				ST.pop();
			}
		}
		else if (S[i] == ']')
		{
			if (ST.top() != S[i])
			{
				cout << "no" << endl;
				break;
			}
			else
			{
				ST.pop();
			}
		}
		else if (S[i] == '}')
		{
			if (ST.top() != S[i])
			{
				cout << "no" << endl;
				break;
			}
			else
			{
				ST.pop();
			}
		}
	}
	if (ST.size()) cout << "no" << endl;
	else cout << "yes" << endl;
	return 0;
}