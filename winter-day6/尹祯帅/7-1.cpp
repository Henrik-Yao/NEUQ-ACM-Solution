#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		vector<int> a;
	for(int i=0;i<n;i++) 
	{
		int q;
		cin>>q;
		a.push_back(q);
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<a[j])
			{
				int t=a[i];
				a.erase(a.begin()+i,a.begin()+i+1);
				a.insert(a.begin()+j,t);
				
				break;
			}
		}
		for(int k=0;k<n-1;k++) cout<<a[k]<<' ';
				cout<<a[n-1]<<'\n';
	}
	}
	return 0;
} 
