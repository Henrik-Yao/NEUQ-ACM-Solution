#include<bits/stdc++.h>
using namespace std;
int n, m, maxx, k, f[303]={0};
struct node
{
	int a, z, w;
	bool operator < (const node &b) const {
        return w<b.w;
    }
}gra[100010];

int find(int x)
{
    if(f[x]!=x) 
        f[x]=find(f[x]);
    return f[x];
}

int main(void)
{
    cin>>n>>m;
	for(int i=1; i<=m; i++)
		cin>>gra[i].a>>gra[i].z>>gra[i].w;
	
	for(int i=1; i<=n; i++)
		f[i]=i;
	sort(gra+1, gra+m+1);
	
	for(int i=1; i<=m; i++)
	{
		if(find(f[gra[i].a])!=find(f[gra[i].z]))
		{
			if(find(gra[i].a)!=find(gra[i].z))
				f[find(gra[i].a)]=find(gra[i].z);
			maxx=gra[i].w;
			k++;
		}
		if(k==n-1)
			break;
	}
	cout<<n-1<<' '<<maxx;
    
    return 0;
}