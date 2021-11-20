#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int nex[1000005],f[1000005];
int ans=0;
void setup_nex(char a[])
{
	nex[0]=0;
	//j表示上一次的匹配了几个 
	for(int i=1,j=0;i<strlen(a);i++)
	{
		//不断缩小长度，直到有可以匹配上的长度 
		while(j&&a[i]!=a[j])j=nex[j-1];//a[j]是上一次匹配成功的前缀的下一个  a[i]是上一个匹配成功的下一个 
		//如果上一次没有匹配成功，则这次的一定最多匹配一个 
		if(a[i]==a[j])j++;
		nex[i]=j;
	}
}
void setup_f(char a[],char b[])//长   短 
{
	int len1=strlen(a);
	int len2=strlen(b);
	for(int i=0,j=0;i<len1;i++)
	{
		while(j&&a[i]!=b[j])j=nex[j-1];
		if(a[i]==b[j])j++;
		f[i]=j;
		if(j==len2)ans++;
	}
}
int main()
{
	char t[1000005],p[1000005];
	cin>>t>>p;//长   短 
	setup_nex(p);
	setup_f(t,p);
	cout<<ans;
	return 0;
}
