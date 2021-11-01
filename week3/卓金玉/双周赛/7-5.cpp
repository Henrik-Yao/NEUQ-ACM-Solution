#include<bits/stdc++.h>
using namespace std;
int main()
{
	int zushu;
	scanf("%d",&zushu);
	while(zushu)
	{
		int m,n,i=0;
		scanf("%d",&m);
		int a[m];
		while(i<m)
		{
			scanf("%d",&a[i]);
			i++;
		}
		scanf("%d",&n);
		i=0;
		int b[n+m];
		while(i<n)
		{
			scanf("%d",&b[i]);
			i++;
		}
		for(int i=0;i<m;++i)
		{
			b[n+i]=a[i];
		}
		for(int i=0;i<m+n;++i)
		{
			for(int j=0;j<m+n-i-1;++j)
			{
				if(b[j]>b[j+1])
				{
					swap(b[j],b[j+1]);
				}
			}
		}
		
		for(int i=0;i<m+n;++i)
		{
			if(!i) printf("%d",b[i]);
			else 
				printf(" %d",b[i]);
		}
        cout<<endl;
		zushu--;
	}
	
	return 0;
}
