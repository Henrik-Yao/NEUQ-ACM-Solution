#include<iostream> 
using namespace std;
int prime[10000010],visited[10000010];

int main()
{
	int i,j,n;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		if(!visited[i])
		{
			prime[++prime[0]]=i;
		}
		for(j=1;j<=prime[0]&&prime[j]*i<=n;j++)
		{
			visited[i*prime[j]] = 1;
            if (i % prime[j] == 0)
            	 break;
		}
	}
	cout<<prime[0];
	return 0;
}
