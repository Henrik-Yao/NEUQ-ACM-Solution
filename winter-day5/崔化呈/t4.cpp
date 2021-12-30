#include<bits/stdc++.h>  
using namespace std;
int a[1010];
int cnt=0;
int find(int n,int x)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		cnt++;
		//cout<<cnt<<endl;
		int mid=(l+r)/2;
		if(x==a[mid]){return mid;}
		else if(x>a[mid]){l=mid+1;}
		else{r=mid-1;}
	}
	return -1;
}
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);
	cout<<find(n,x)<<endl<<cnt;
	return 0;
}
