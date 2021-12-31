#include<bits/stdc++.h>
using namespace std; 
int n,id,f,m,k,flag=0;
string g;
int gen[100000],fa[100000],mo[100000];
void tonghun(int a,int b,int t)
{
	if(t>=4)
	{
		return;
	}
	if((mo[a]!=-1&&mo[b]!=-1&&mo[a]==mo[b])||(fa[a]!=-1&&fa[b]!=-1&&fa[a]==fa[b]))
    {
	    flag=1;
        return;
	}
    if(mo[a]!=-1&&fa[b]!=-1)
    {
    	tonghun(mo[a],fa[b],t+1);
	}
	if(mo[a]!=-1&&mo[b]!=-1)
	{
	    tonghun(mo[a],mo[b],t+1);	
	}
	if(fa[a]!=-1&&fa[b]!=-1)
	{
		tonghun(fa[a],fa[b],t+1);
	}   
    if(fa[a]!=-1&&mo[b]!=-1)
    {
    	tonghun(fa[a],mo[b],t+1);
	}
    return;
}
int main()
{
	int i;
	memset(fa,-1,sizeof(fa));
	memset(mo,-1,sizeof(mo));
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>id>>g>>f>>m;
		if(g=="M")
		{
			gen[id]=1;
		}
		else
		{
			gen[id]=0;
		}
		fa[id]=f;
		gen[f]=1;
		mo[id]=m;
		gen[m]=0;
	}
	cin>>k;
	for(i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		if(gen[a]==gen[b])
		{
			cout<<"Never Mind"<<endl;
		}
		else
		{
			flag=0;
			tonghun(a,b,0);
			if(flag==0)
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
	}
	return 0;
}
