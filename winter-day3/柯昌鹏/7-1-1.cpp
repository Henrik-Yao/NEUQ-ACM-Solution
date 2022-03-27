#include <bits/stdc++.h>
using namespace std;

struct node{
	int from;
	int t;
	int w;
};

bool cmp(node a,node b)
{
	if(a.from!=b.from) return a.from<b.from;
	return a.t<b.t;
}

node a[20005];
int con[20005];

int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a[i].from>>a[i].t>>a[i].w;
		con[a[i].from]++;
	}
	sort(a,a+m,cmp);
	int sum=0;
    for(int i=0;i<n;i++)
	{
		if(con[i]==0) continue;//当这个顶点没有边的时候跳过循环
		printf("%d:",a[sum].from);
		for(int j=sum;j<con[i];j++)
		{
            printf("(%d,%d,%d)",a[j].from,a[j].t,a[j].w);
		}
		sum+=con[a[i].from];
		cout<<endl;
	}

	return 0;
}