#include<bits/stdc++.h>
using namespace std;
 int n,sum,summ1=0,summ2=0;
bool b1[100001],b2[100001];
int a[1000001],c1[1000001],c2[1000001];
int main()
{
   
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(b1[a[i]]==0)
		{
			b1[a[i]]=1;//属于是非常优秀的一种查重方法了
			summ1++;
		}
		c1[i]=summ1;
	}
	for(int i=n-1;i>=0;i--)
	{
		if(b2[a[i]]==0)
		{
			b2[a[i]]=1;//属于是非常优秀的一种查重方法了
			summ2++;
		}
		c2[i]=summ2;
		sum=max(sum,c1[i]+c2[i+1]);
	}//这就是枚举断点吗！！！！好优秀！！！
	cout<<sum;
    return 0;
}
