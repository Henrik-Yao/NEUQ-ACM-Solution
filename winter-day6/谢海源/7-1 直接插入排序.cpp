#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int main()
{
	int a[maxn];
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<n;i++)
		{
			int key=a[i];
			for(int j=i-1;j>=0;j--)
			{
				if(key<a[j])
				{
					a[j+1]=a[j];//后移
					a[j]=key;
				}
			}
			
			for(int j=0;j<n-1;j++) cout<<a[j]<<" ";
			cout<<a[n-1]<<endl;
		}
	}
	return 0;
}