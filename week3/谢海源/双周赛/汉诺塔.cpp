#include<bits/stdc++.h>
using namespace std;
string a[4];
void f(int n,int from,int use,int to)//from，use，to
{
	if(n==1) cout<<a[from]<<"->"<<a[to]<<endl;
	else
	{
		f(n-1,from,to,use);
		cout<<a[from]<<"->"<<a[to]<<endl;
		f(n-1,use,from,to);
	}
}
int main()
{
	int n;
	cin>>n;
	cin>>a[1]>>a[2]>>a[3];
	f(n,1,2,3);
	return 0;	
}
