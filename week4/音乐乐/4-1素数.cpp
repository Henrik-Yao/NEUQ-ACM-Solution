#include<iostream> 
using namespace std;
int prime[10010],visited[10010];

int main()
{
	int i,j;
	for(i=2;i<=10000;i++)
	{
		if(!visited[i])
		{
			prime[++prime[0]]=i;
		}
		for(j=1;j<=prime[0]&&prime[j]*i<=10000;j++)
		{
			visited[i*prime[j]] = 1;
            if (i % prime[j] == 0)
            	 break;
		}
	}
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		for(i=1;i<=prime[0];i++)
		{
			if(prime[i]>=a&&prime[i]<=b)
			cout<<prime[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
