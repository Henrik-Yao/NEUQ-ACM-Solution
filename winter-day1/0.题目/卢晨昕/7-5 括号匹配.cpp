#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
char z[100005];
int top;
string a;
int main()
{
	while(cin>>a)
	{
		int ans=0,top=0;
		for(int i=0;i<a.length();i++)
		{
			if(a[i]=='(')
			{
				z[++top]=a[i];
			}
			else
			{
				if(top==0)
				{
					ans++;
				}
				else top--;
			}
		}
		if(ans==0&&top==0)
		{
			cout<<"Match"<<endl;
		}
		else
		{
			cout<<ans+top<<endl;
			for(int i=1;i<=ans;i++)cout<<"(";
			cout<<a;
			for(int i=1;i<=top;i++)cout<<")";
			cout<<endl;
		}
	}
	return 0;
}
