#include<bits/stdc++.h>
using namespace std;
const int mm=10005;
int main()
{
	int judge[mm]={},result[mm];
	int a,b,cnt=0;
	judge[0]=1;judge[1]=1;
	for(int i=2;i<=10000;i++)
	{
		for(int j=2;i*j<=10000;j++)
		{
			judge[i*j]=1;
		}
		if(judge[i]==0)
		result[++cnt]=i;
	}
	while(cin>>a>>b)
	{
		int flag;
		for(int i=1;i<=cnt;i++)
		if(result[i]>=a)
		{
			flag=i;
			break;
		}
		int i;
		for(i=flag;result[i+1]<=b;i++)
		cout<<result[i]<<" ";
		cout<<result[i];
		cout<<endl;
	}
	
}
