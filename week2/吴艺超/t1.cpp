#include<bits/stdc++.h>
#include<cmath>
#define R register
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;ch=getchar(); 
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48),ch=getchar();
	}
	return x*f;

}
int N;
int tot,ans;
void move(int n,string a,string b,string c)
{
		if(n==1)
		{
			cout<<a<<"->"<<c<<endl;
		}
		else 
		{
			move(n-1,a,c,b);
			cout<<a<<"->"<<c<<endl;
			move(n-1,b,a,c);
		}
}
int main()
{
	string a,b,c;
	cin>>N>>a>>b>>c;
	move(N,a,b,c);
	return 0;
}
