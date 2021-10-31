#include<iostream>
using namespace std;
int main()
{
	int n,T,happy=0,temp;
	scanf("%d %d",&n,&T);
	int a[n],b[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d %d",&a[i],&b[i]);
		if(b[i]<=T)
		{
			if(happy<=b[i])
			{
				happy=a[i];
			}
		}
		else
		{
			temp=a[i]-(b[i]-T);
			if(happy==0||happy<temp)
			{
				happy=temp;
			}
		}
	}
	printf("%d",happy);
	return 0;
}
