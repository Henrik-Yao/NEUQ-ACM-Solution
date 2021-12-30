#include<bits/stdc++.h>
using namespace std;
int a[105];

int searc(int tar, int n);

int main()
{
	int n,m;
	while(cin>>n)
    {
		for(int i=0;i<n;i++)
			cin >> a[i];

		sort(a,a+n);

		for(int i = 0; i < n-1; i++)
			cout<<a[i]<<" ";

		cout<<a[n-1]<<endl;
		cin>>m;

		int tar;
		for(int i=0;i<m;i++)
        {
			cin>>tar;
			cout<<searc(tar,n)+1;
			if(i!=m-1)
                cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}

int searc(int tar, int n)
{
	int mid;
	int l=0,r=n-1;
	while(l<=r)
    {
		mid=l+(r-l)/2;

		if(a[mid]==tar)
			return mid;

		if(tar<a[mid])
			r=mid-1;
        else
			l=mid+1;
	}
	return -1;
}

