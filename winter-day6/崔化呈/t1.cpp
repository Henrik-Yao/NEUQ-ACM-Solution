#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			int num;
			scanf("%d",&num);
			v.push_back(num);
		}
		for(int i=1;i<n;i++)
		{
			int m=v[i];
			int j;
			for(j=i-1;j>=0&&v[j]>m;j--)
			{
				v[j+1]=v[j];
			}
			v[j+1]=m;
			int sz=v.size();
			for(int j=0;j<sz-1;j++)
			{
				
				printf("%d ",v[j]);
			}
			printf("%d\n",v[sz-1]);
		}
		v.clear();
	}
	return 0;
}

