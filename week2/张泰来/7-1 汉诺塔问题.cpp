#include <bits/stdc++.h>
using namespace std;
int n;
string s[15];
void Hanoi(int src,int mid,int dst,int num)
{
	if (num == 1)
	{
		cout << s[src] << "->" << s[dst] << endl;
		return;
	}
	Hanoi(src,dst,mid,num - 1);
	cout << s[src] << "->" << s[dst] << endl;
	Hanoi(mid,src,dst,num - 1);
	return;
}
int main()
{
	cin >> n;
	for (int i = 1;i <= 3; i++)
	{
		cin >> s[i];
	}
	Hanoi(1,2,3,n);
	return 0;
}
