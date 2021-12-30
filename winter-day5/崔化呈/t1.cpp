#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num[1010];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){scanf("%d",&num[i]);}
	sort(num,num+n);
	int cnt=0;
	for(int i=0;i<n-1;i++)
	{
		if(num[i+1]-num[i]==1){cnt++;}
	}
	printf("%d",cnt);
	return 0;
}
