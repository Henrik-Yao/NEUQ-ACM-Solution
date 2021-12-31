#include<bits/stdc++.h>
using namespace std;
int n,m,s,sum=0,k=0;
int fat[200010]; 
typedef struct edge
{
	int from,to,weight; 
}edge;
bool cmp(edge a,edge b) 
{
	return a.weight<b.weight;
}
int fff[200010];
int get(int n)
{
    if(fff[n]==n)
        return n;
    else
        return get(fff[n]);
}
void bin(int x,int y)
{
    int f1,f2;
    f1=get(x);
    f2=get(y);
    if(f1!=f2)
        fff[f1]=f2;
}
int main()
{
	while(cin>>n>>s>>m)
    {
        k=0;
            
edge ed[200010];
        memset(fff,0,n+1);
        sum=0;
	for(int i=1;i<=m;i++)
	{
		cin>>ed[i].from>>ed[i].to>>ed[i].weight ;
	}
        for(int i=1;i<=n;i++)
            fff[i]=i;
	sort(ed+1,ed+1+m,cmp); 
        int num=0;
	for(int i=1;i<=m;i++)
	{
		if(k==n-1) break;
        if((ed[i].from==s||ed[i].to==s)&&num<2)
        {
            if(get(ed[i].from)!=get(ed[i].to))
        {
            bin(ed[i].from,ed[i].to);
            sum+=ed[i].weight;
            k++;
                num++;
        }
        }
        else if(ed[i].from==s||ed[i].to==s&&num==2)
            continue;
        else
        {
            if(get(ed[i].from)!=get(ed[i].to))
        {
            bin(ed[i].from,ed[i].to);
            sum+=ed[i].weight;
            k++;
        }
        }
		
        
    }
        if(k==n-1)
        {
            cout<<sum<<endl;
        }
        else
            cout<<-1<<endl;
    }
}
