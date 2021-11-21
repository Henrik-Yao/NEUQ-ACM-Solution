#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int a[N];
int main()
{
	int n,m,t,flag=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		if(m<=a[i]&&!flag)
		{
			cout<<i+1;
			flag=1;
            break;
		}
	}
	if(!flag)
	{
		cout<<n+1;
	}
    
	return 0;
}
