#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int sum=0;
int v[1000005];//记录第i个字串是否被匹配过 
int id[1000005];//记录第i个字符属于第几个子串 
void starta(char a[])
{
	int flag=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]=a[i]-'A'+'a';
		}
		if(a[i]>='a'&&a[i]<='z')
		{
			if(flag==0)
			{
				sum++;
				flag=1;
			}
			id[i]=sum;
		}
		else
		{
			flag=0;
		}
	}
}
void startb(char b[])
{
	for(int i=0;i<strlen(b);i++)
	{
		if(b[i]>='A'&&b[i]<='Z')
		{
			b[i]=b[i]-'A'+'a';
		}
	}
}

int ans=0;
int nex[100005];
void setup_nex(char b[])
{
	nex[0]=0;
	for(int i=1,j=0;i<strlen(b);i++)
	{
		while(j&&b[i]!=b[j])j=nex[j-1];
		if(b[i]==b[j])j++;
		nex[i]=j;
	}
}
void kmp(char a[],char b[])//长   短
{
	int len1=strlen(a);
	int len2=strlen(b);
	for(int i=0,j=0;i<len1;i++)
	{
		while(j&&a[i]!=b[j])j=nex[j-1];
		if(a[i]==b[j])j++;
		if(j==len2)
		{
			if(v[id[i]]==0)
			{
				v[id[i]]=1;
				ans++;
			}
		}
	}
}
int main()
{
	char a[1000005],b[1000005];
	cin.getline(a,1000005);
	cin.getline(b,1000005);
	starta(a);
	startb(b);
	setup_nex(b);
	kmp(a,b);
	cout<<ans;
	return 0;
}
