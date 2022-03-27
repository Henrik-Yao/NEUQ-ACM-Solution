#include<bits/stdc++.h>
using namespace std;
int pre[30],f[30];
struct node
{
	int l,r;
}order[100];
bool cmp(node x,node y)
    {
    	return x.r<y.r;
	}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		memset(pre,0,sizeof(pre));
		memset(f,0,sizeof(f));
		f[1]=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>order[i].l>>order[i].r;
		sort(order+1,order+n+1,cmp);
		for(int i=n;i>=1;i--)
		for(int j=n-1;j>=1;j--)
		if(order[j].r<=order[i].l)
		{
			pre[i]=j;
			break;
		}
		for(int i=2;i<=n;i++)
		f[i]=max(f[i-1],1+f[pre[i]]);
		cout<<n-f[n]<<endl;
	}
}
