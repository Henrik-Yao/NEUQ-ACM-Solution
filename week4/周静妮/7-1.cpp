#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,i,j,n,m=0;
	while(cin>>a>>b)
	{
		
		int c[10000];
		memset(c, 0, sizeof(c));
		c[0] = c[1] = 1;
		for(i = 2;i <= b;i++)
			if(!c[i]) 	for(j = i*i;j <= b;j += i)	c[j] = 1;
		n=0;
		for(i = a;i <= b;i++)
			if(!c[i])
			{
				if(!n) n++;
				else cout<<' ';
				cout<<i;
			}
		cout<<endl;
	}
	
	return 0;
}
