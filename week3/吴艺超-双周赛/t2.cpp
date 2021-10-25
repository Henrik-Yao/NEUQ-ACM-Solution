#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n;
string a,b,c;
void move(int n,string a,string b,string c)
{
	if(n==1)
	{
		cout<<a<<"->"<<c<<endl;
		return;
	}
	move(n-1,a,c,b);
	cout<<a<<"->"<<c<<endl;
	move(n-1,b,a,c);
}
int main()
{
	cin>>n>>a>>b>>c;
	move(n,a,b,c);
	return 0;
}
