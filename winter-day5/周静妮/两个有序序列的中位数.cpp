#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn],c[2*maxn];

int main()
{
	int n,i,k,j,t;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) cin>>b[i];
	k=i=j=0;
	while(i<n && j<n)
	{	
		if(a[i]<=b[j])	
		{
			c[k]=a[i];
			i++;
			k++;		
		}
		else if(a[i]>b[j])	
		{
			c[k]=b[j];
			j++;
			k++;
		}	
	}
	if(i<n)
		for(;i<n;i++) 
		{
			c[k]=a[i];
			k++;
		}	
	else if(j<n)
		for(;j<n;j++,k++)	c[k]=b[j];
	t=(k-1)/2;
	cout<<c[t];
	return 0;
}
