#include<stdio.h>
//#include<bits/stdc++.h>
#include<string.h>
#define ll long long 
#define N 1000000
//using namespace std;
char a1[N+10],b[N+10],a[100][N+10];
int net[N+10];
int f[N+10];
int cnt;
int num=1;
void ks()
{
	int len=strlen(a1);
//	cout<<len<<endl;
	int tot=0,flag=0;
	for(int i=0;i<len;i++)
	{
		if(a1[i]>='A'&&a1[i]<='Z')a1[i]+=32;
		if(a1[i]>='a'&&a1[i]<='z')
		{
			if(flag==1)
			{
				flag=0,tot=0;
				num++;
			}
			if(flag==0)a[num][++tot]=a1[i];
		}
		if(a1[i]<'a'||a1[i]>'z')flag=1;
	}
}
void ps()
{
	int len=strlen(b+1);
	for(int i=1;i<=len;i++)
	{
		if(b[i]>='A'&&b[i]<='Z')b[i]+=32;
	}
}
int main()
{
	gets(a1),gets(b+1);
//	cout<<strlen(b)<<endl;
	ks(),ps();
//	printf("%c",b[1]);
 	int m=strlen(b+1);
    net[1]=0;
	for(int i=2,j=0;i<=m;i++)
	{
		while(j&&(b[i]!=b[j+1]))j=net[j];
		if(b[i]==b[j+1])j++;
		net[i]=j;
	}
	while(num)
	{
		int n=strlen(a[num]+1);
		//cout<<n<<endl;
		for( int i=1,j=0;i<=n;i++)
		{
			while(j&&(a[num][i]!=b[j+1]))j=net[j];
			if(a[num][i]==b[j+1])j++;
			if(j==m)
			{
				cnt++;
				break;
			}
		}
		num--;
	}
	printf("%d",cnt);
//	cout<<num<<endl;
	return 0;
}
