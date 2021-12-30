#include <bits/stdc++.h>
using namespace std;
vector<int>q;
int main()
{
	int n,a[1001];
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(a[j+1]<a[j])
				{
					swap(a[j],a[j+1]);
				}
			}
			for(int j=0;j<n;j++)
			{
				cout<<a[j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
