#include<bits/stdc++.h>
#define ll long long 
#define N 1000000
using namespace std;
char a[N+10],b[N+10];
int net[N+10];
int f[N+10];
int cnt;
int main()
{
	scanf("%s%s",a+1,b+1);
    int n=strlen(a+1);
    int m=strlen(b+1);
    net[1]=0;
    for(int i=2,j=0;i<=m;i++)
    {
    	while(j&&(b[i]!=b[j+1]))j=net[j];
    	if(b[i]==b[j+1])j++;
    	net[i]=j;
	}
	for(int i=1,j=0;i<=n;i++)
	{
		while(j&&(a[i]!=b[j+1]))j=net[j];
		if(a[i]==b[j+1])j++;
		if(j==m)cnt++;
	}
	cout<<cnt;
	return 0;
}
