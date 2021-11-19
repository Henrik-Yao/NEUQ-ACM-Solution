#include <bits/stdc++.h>
using namespace std;
char a[1000001],b[1000001];
int kmp[1000001],la,lb,j,ans=0;
int main()
{
	cin>>a+1;
	cin>>b+1;
	la=strlen(a+1);
	lb=strlen(b+1);
	for(int i=2;i<=lb;i++)
	{
		while(j!=0&&b[i]!=b[j+1])
		{
			j=kmp[j];
		}
		if(b[i]==b[j+1])
		j++;
		kmp[i]=j;
	}
	j=0;
	for(int i=1;i<=la;i++)
	{
		while(j>0&&b[j+1]!=a[i])
		{
			j=kmp[j];
		}
		if(b[j+1]==a[i])
		{
			j++;
		}
		if(j==lb)
		{
			ans++;
			j=kmp[j];
		}
	}
	cout<<ans;
	return 0;
}
