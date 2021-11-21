#include<bits/stdc++.h>
using namespace std;
#define MAX 10010
int main()
{
	int num[MAX],a,b;
	memset(num,0,sizeof(num));
	for(int i=2;i<=MAX;i++)
	{
		if(!num[i])
		{
			for(int j=2*i;j<=MAX;j+=i)
			{
				num[j]=1;
			}
		}
	}
	while(cin>>a>>b)
	{
		int nu[10000],ge=0;
		for(int i=a;i<=b;i++)
		{
			if(num[i]==0){nu[ge++]=i;}
		}
		for(int i=0;i<ge-1;i++)
		{
			cout<<nu[i]<<" "; 
		}		
		cout<<nu[ge-1]<<endl;
	}
	return 0;
}
