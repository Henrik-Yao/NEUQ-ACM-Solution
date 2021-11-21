#include<bits/stdc++.h>
using namespace std;
const int M=10001;
int a[M];
int main()
{
	memset(a,0,M);//保证数组最开始都是0 
	for(int i=2;i<=M;i++)
	{
		if(!a[i])//如果为0，证明之前没有被筛过，说明是素数 
		{
			for(int j=i*i;j<=M;j+=i)//标记所有素数的倍数 
			{
				a[j]=1;
			}
		}
	}
	int c,b;
	while(cin>>c>>b)
	{
		int m=0;
		for(int i=c;i<=b;i++)
		{
			if(!a[i])
			{
				if(m!=0)
				{
					cout<<" ";
				}
				cout<<i;
				m=1;
			}
		}
		cout<<endl;
	}
}
