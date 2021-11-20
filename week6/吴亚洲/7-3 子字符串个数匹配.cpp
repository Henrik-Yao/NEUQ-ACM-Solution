#include<bits/stdc++.h>
using namespace std;
#define M 100006
char s1[M],s2[M];
int p[M];
int j=0,cnt=0;
int main()
{
	cin.getline(s1+1,M);
	for(int i=1;i<=strlen(s1+1);i++)
	if(s1[i]>='A'&&s1[i]<='Z')
	s1[i]+=('a'-'A');
	cin>>s2+1;
	for(int i=1;i<=strlen(s2+1);i++)
	if(s2[i]>='A'&&s2[i]<='Z')
	s2[i]+=('a'-'A');
	int len1=strlen(s1+1),len2=strlen(s2+1);
	for(int i=2;i<=len2;i++)
	{
		while(j&&s2[j+1]!=s2[i])
		j=p[j];
		if(s2[i]==s2[j+1])
		j++;
		p[i]=j;
	}
	j=0;
	int flag=0;
	for(int i=1;i<=len1;i++)
	{
		if(s1[i]<'a'||s1[i]>'z')
		flag=0;
		if(flag==1)
		continue;
		while(j&&s1[i]!=s2[j+1])
		j=p[j];
		if(s2[j+1]==s1[i])
		j++;
		if(j==len2)
		{
			j=p[j];
			cnt++;
			flag=1;
		}
	}
	cout<<cnt;
}
