#include<iostream>
#include<stack>
using namespace std;
stack<char>ST;
int main()
{
	string S;
	cin >> S;
	int length = S.length(), i;
	for (i = 0; i < length - 1; i++)
	{
		if (S[i] == 'A') cout << "sae";
		else if (S[i] == 'B') cout << "tsaedsae";
		else if (S[i] == '(')
		{
			i++;
			int k = i + 1;
			while (S[k] != ')')
			{
				ST.push(S[k]);
				k++;
			}
			while (ST.size())
			{
				cout << S[i] << ST.top();
				ST.pop();
			}
			cout << S[i];
			i = k;
		}
		else cout << S[i];
	}
	return 0;
}
