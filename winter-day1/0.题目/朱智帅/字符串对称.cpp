#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int main()
{
	string S;
	cin >> S;
	int length = S.length(), i;
	stack<char>ST;
	for (i = 0; i < length; i++)
		ST.push(S[i]);
	bool tag = true;
	for (i = 0; i < length; i++)
	{
		if(ST.top()==S[i]);
		else
		{
			tag = false;
			break;
		}
		ST.pop();
	}
	if (tag) cout << "yes";
	else cout << "no";
	cout << endl;
	return 0;
}