#include<bits/stdc++.h>
using namespace std;
int n, m, f[1510]={0};
struct edge
{
	int a, z, w;
	bool operator < (const edge &b) const {
        return w<b.w;
    }
};

int find(int x)
{
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}

int main(void)
{
	while(cin>>n>>m)
    {
    	edge gra[m+10];
    	for(int i=1; i<=m; i++)
			cin>>gra[i].a>>gra[i].z>>gra[i].w;
		
		memset(f, 0, 4*1510);
		for(int i=1; i<=n; i++)
			f[i]=i;
		sort(gra+1, gra+m+1);
		
		int k=0, s=0;
		for(int i=1; i<=m; i++)
		{
			if(find(f[gra[i].a])!=find(f[gra[i].z]))
			{
				if(find(gra[i].a)!=find(gra[i].z))
					f[find(gra[i].a)]=find(gra[i].z);
				s+=gra[i].w;
				k++;
			}
			if(k==n-1)
				break;
		}
		if(k==n-1)
			cout<<s<<endl;
		else
			puts("There is no minimum spanning tree.");
	}
	
    
    return 0;
}