#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
int main()
{
	int n,i,j,k,t,m,left,mid,right,sum=0;
	int a[maxn];
	cin>>n;
	for(i=0;i<n;i++)	cin>>a[i];
	cin>>t;
	left=0;
	right=n-1;
	bool flag=0;
	while(left<=right)
	{
		sum++;
		mid=(left+right)/2;
		if(a[mid]==t)
		{
			flag=1;
			break;
		}
		else if(a[mid]<t)	left=mid+1;
		else if(a[mid]>t)	right=mid-1;	
	}	
	if(flag)	cout<<mid<<endl;
	else  cout<<"-1"<<endl;
	cout<<sum<<endl;
	return 0;
}
