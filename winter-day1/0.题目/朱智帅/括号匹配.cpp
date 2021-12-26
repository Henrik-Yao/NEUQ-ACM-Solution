#include<iostream>
using namespace std;
int main()
{
	string S;
	while (cin >> S)
	{
		int i, incnt = 0, outcnt = 0, sum = 0, length;
		length = S.length();
		for (i = 0; i < length; i++)
		{
			if (S[i] == '(')
			{
				incnt++;
			}
			if (S[i] == ')')
			{
				if (incnt) incnt--;
				else outcnt++;
			}
		}
		if ((!incnt) && (!outcnt)) cout << "Match" << endl;
		else
		{
			sum = incnt + outcnt;
			cout << sum << endl;
			for (i = 0; i < outcnt; i++) cout << "(";
			cout << S;
			for (i = 0; i < incnt; i++) cout << ")";
			cout << endl;
		}
	}
}