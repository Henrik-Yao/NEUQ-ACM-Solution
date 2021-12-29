#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a;
	int b;
	int w;
};
node nn[20010];
int s[20010];
bool cmp(node aa,node bb)
{
	if(aa.a!=bb.a){return aa.a<bb.a;}
	return aa.b<bb.b;
}
int main()
{
	int n,e,a,b,w;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>nn[i].a>>nn[i].b>>nn[i].w;
		s[nn[i].a]++;
	}
	sort(nn,nn+e,cmp);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!=0)
		{
			cout<<i<<':';
			for(int j=0;j<s[i];j++)
			{
				printf("(%d,%d,%d)",nn[cnt].a,nn[cnt].b,nn[cnt].w);
				cnt++;
			}
			cout<<endl;
		}
	}
	return 0;
}
