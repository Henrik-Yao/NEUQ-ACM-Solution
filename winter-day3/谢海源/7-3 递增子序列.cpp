#include<bits/stdc++.h>
using namespace std;
const int maxn = 210;
int a[maxn];
bool v2[maxn]={};
int sum = 0;
struct edge
{
	int from, to;
	edge(int a, int b)
	{
		from = a; to = b;
	}
};
vector<edge>ed[maxn];
void getup(int num)
{
	int v[maxn]={};
	for (auto& k : ed[num])//遍历该点线段
	{	
		if(v[a[k.to]])continue;
		v[a[k.to]]=1;
		sum++;
		//cout << a[k.from] << " " << a[k.to] << endl;
		getup(k.to);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		//a[i]+=100;//有负数默认加100
	}
	for (int i = 0; i < n; i++) ed[i].clear();//初始化
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] <= a[j])
			{
				ed[i].push_back(edge(i, j));//做序号的有向连接
			}
		}
	}
	//for(int i=0;i<n;i++) getup(i);
	for (int i = 0; i < n;i++)
	{
		if(v2[a[i]]) continue;
		v2[a[i]]=1;
		//cout<<a[i]<<endl;
		getup(i);
	}
	cout << sum;
	return 0;
}