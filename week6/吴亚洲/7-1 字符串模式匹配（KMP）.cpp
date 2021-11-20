#include<bits/stdc++.h>
using namespace std;
#define M 1000005
char s1[M],s2[M];
int p[M];
int j=0,cnt=0;
int main()
{
	cin>>s1+1;
	cin>>s2+1;
	int len1=strlen(s1+1),len2=strlen(s2+1);
	for(int i=2;i<=len2;i++)
	{
		while(j&&s2[i]!=s2[j+1])
		j=p[j];
		if(s2[i]==s2[j+1])
		j++;
		p[i]=j;
	}
	j=0;
	for(int i=1;i<=len1;i++)
	{
		while(j&&s1[i]!=s2[j+1])
		j=p[j];
		if(s1[i]==s2[j+1])
		j++;
		if(j==len2)
		{
			cnt++;
			j=p[j];
		}
	}
	cout<<cnt;
}
