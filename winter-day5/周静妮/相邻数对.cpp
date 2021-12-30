#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,sum=0;
	int a[1001];
	cin>>n;
	for(i=0;i<n;i++)	cin>>a[i];
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		if(fabs(a[i]-a[j])==1) sum++;
	cout<<sum<<endl;
	return 0;
}
