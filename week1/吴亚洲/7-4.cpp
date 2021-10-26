#include<bits/stdc++.h>
using namespace std;
long long num=0;
int fen(int n)
{
	num++;
	for(int i=1;i<n;i++)
	if(n%i==0)
	fen(i);
}
int main()
{
	int n;
	cin>>n;
	fen(n);
	cout<<num;
	return 0;
}
