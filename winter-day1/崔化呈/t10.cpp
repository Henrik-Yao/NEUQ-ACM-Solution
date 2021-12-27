#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int qn=0,t,a[101],b[101],bn=1;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(qn==0){a[qn++]=t;b[0]=t;}
		else if(a[qn-1]<t){a[qn++]=t;}
		else
		{
			int r=qn-1,l=0,mid;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(a[mid]>t){r=mid-1;}
				else{l=mid+1;}
			}
			a[l]=t;
			if(l==0){b[bn++]=t;}
		}
		
	}
	for(int i=0;i<bn;i++)
	{
		if(i==bn-1){cout<<b[i]<<endl;}
		else{cout<<b[i]<<" ";}
	}
	cout<<qn<<endl;
	return 0;
}
