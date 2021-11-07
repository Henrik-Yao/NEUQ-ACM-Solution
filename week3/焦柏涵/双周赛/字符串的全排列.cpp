#include <bits/stdc++.h>
using namespace std;
int n,c[10];
char a[10],b[10];
void pailie(int m,int n)
{
	if(m==n+1)//可输出全排列和返回上一层递归的条件 
	{
		for(int i=0;i<=n;i++) cout<<b[i];//注：输出的是b数组 
		cout<<endl;
		return;
	} 
	for(int i=0;i<=n;i++)
	{
		if(c[i]==1) continue;
		b[m]=a[i];//“临时”存储 
		c[i]=1;
		pailie(m+1,n);
		c[i]=0;
	}
}
int main()
{
	cin>>a;
	n=strlen(a)-1;
	sort(a,a+strlen(a));
	//for(int i=0;i<=n;i++) cout<<a[i];
	pailie(0,n);
	return 0; 
}
