#include <bits/stdc++.h>
using namespace std;
int n,t;
vector <int> v;
void adjust(int rt,int size)
{
	int pos = rt;
	int lson = 2 * rt + 1;
	int rson = 2 * rt + 2;
	if (lson < size && v[lson] > v[pos])  pos = lson;
	if (rson < size && v[rson] > v[pos])  pos = rson;
	if (pos != rt)
	{
		swap(v[pos],v[rt]);
		adjust(pos,size);
	}
	return;
}
void heap_sort()
{
	for (int i = n / 2 - 1;i >= 0; i--)
	{
		adjust(i,n);
	}
	for (int i = 0;i < n; i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
	for (int i = n - 1;i >= 1; i--)
	{
		swap(v[0],v[i]);
		adjust(0,i);
		for (int j = 0;j < n; j++)
		{
			printf("%d ",v[j]);
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n; i++)
	{
		scanf("%d",&t);
		v.push_back(t);
	}
	heap_sort();
	return 0;
}
