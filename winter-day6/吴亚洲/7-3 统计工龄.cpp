#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n;
	cin>>n;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;)
	{
		int t=a[i],cnt=0;
		while(a[i]==t&&i<=n)
		{
			i++;
			cnt++;
		}
		cout<<t<<":"<<cnt<<endl;
	}
}
