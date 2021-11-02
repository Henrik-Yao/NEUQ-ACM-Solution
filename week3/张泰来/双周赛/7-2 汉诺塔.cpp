#include <bits/stdc++.h>
using namespace std;
int n;
string s[5];
void Hannoi(int sur,int midd,int dst,int step)
{
	if (step == 1)
	{
		cout << s[sur] << "->" << s[dst] << endl;
		return;
	}
	Hannoi(sur,dst,midd,step - 1);
	cout << s[sur] << "->" << s[dst] << endl;
	Hannoi(midd,sur,dst,step - 1);
	return;
}
int main()
{
	cin >> n;
	for (int i = 1;i <= 3; i++)
	{
		cin >> s[i];
	}
	Hannoi(1,2,3,n);
	return 0;
} 
