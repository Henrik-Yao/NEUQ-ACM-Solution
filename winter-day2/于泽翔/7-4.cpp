#include <bits/stdc++.h>
using namespace std;
int n, m, q, f[1010]={0}, a, b;
int find(int k)
{
	if(f[k]==k)
		return k;
	return f[k]=find(f[k]);
}

int main(void)
{
	cin>>n>>m>>q;
    for(int i=1; i<=n; i++)
        f[i]=i;
    
    while(m--)
    {
        cin>>a>>b;
        f[find(a)]=find(b);
    }
    while(q--)
    {
        cin>>a>>b;
        if(find(a)==find(b))
            puts("In the same gang.");
        else
            puts("In different gangs.");
    }
    int tot=0;
    for(int i=1; i<=n; i++)
    	if(f[i]==i)
    		tot++;
	cout<<tot;
	
	return 0;
}