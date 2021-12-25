#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[10000],b[10000],c[1000],sum=1,tot=1,tp=1;
int main()
{
	int x;
	while(cin>>x)
	{
		a[tot++]=x;
		if(x%2==0)
		b[sum++]=x;
		else c[tp++]=x;
	}
	tot--;sum--;tp--;
	sort(a+1,a+tot+1);
	sort(b+1,b+sum+1);
	sort(c+1,c+tp+1);
	for(int i=1;i<=tot;i++)
	{
		if(i!=tot)cout<<a[i]<<"->";
		else cout<<a[i];
	}
	cout<<endl;
	for(int i=1;i<=tp;i++)
	{
		if(i!=tp)cout<<c[i]<<"->";
		else cout<<c[i];
	}
	cout<<endl;
		for(int i=1;i<=sum;i++)
	{
		if(i!=sum)cout<<b[i]<<"->";
		else cout<<b[i];
	}
	cout<<endl;
	return 0;
}
