#include<bits/stdc++.h> 
using namespace std;
int main()
{
	char a[9];
	int i,j,n;
	cin>>a;
	n=strlen(a);
	sort(a,a+n);
	int num=1;
	for(i=1;i<=n;i++)
	num*=i;
	for(i=0;i<n;i++)
	cout<<a[i];
	cout<<endl;
	for(i=j;j<=num-1;j++)
	{
		next_permutation(a,a+n);
		for(i=0;i<n;i++)
		cout<<a[i];
		cout<<endl;
	}
	return 0;
}
