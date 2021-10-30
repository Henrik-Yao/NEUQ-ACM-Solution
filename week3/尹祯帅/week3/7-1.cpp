#include<bits/stdc++.h>
using namespace std;
int n,k,b[102],c[102];
bool jud[111],ju=0;
void lujing(int s,int d);
int main()
{
	int m,s,d;
	cin>>m>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		jud[a[i]]=1;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i]>>c[i];
	}
	cin>>s>>d;
	if(jud[d])
	{
		lujing(s,d);
		if(ju) cout<<"The city "<<d<<" can arrive safely!";
		else cout<<"The city "<<d<<" can not arrive safely!";
	}
	else cout<<"The city "<<d<<" is not safe!";
	return 0;
 } 
 void lujing(int s,int d)
{
	if(s==d) ju=1;
	else 
	for(int i=1;i<=k;i++) 
	{
		if(b[i]==s) 
		{
			if(jud[c[i]]) 
			lujing(c[i],d);
		}
		else if(c[i]==s)
		{
			if(jud[b[i]]) lujing(b[i],d);
		}
	}
}
