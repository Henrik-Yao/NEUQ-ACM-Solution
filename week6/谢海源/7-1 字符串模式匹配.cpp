#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;//字符串长度最大值为maxn
const int base=1776840;//进制
const int mod = 1e9 + 7;
char s1[maxn],s2[maxn];
int power[maxn], ha[maxn];
int get(int l,int r)
{
    return (ha[r] - ha[l - 1]*power[r-l+1]%mod + mod)%mod;//求子串
}
void init()//预处理
{
	power[0]=1;
	for(int i=1;i<=maxn;i++)
	{
		power[i]=power[i-1]*base%mod;
	}
}
signed main()
{
	init();//预处理
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int len1=strlen(s1+1),len2=strlen(s2+1);
	ha[0]=0;
	for(int i=1;i<=len1;i++)//文章串
	{
		ha[i]=(ha[i-1]*base%mod+(s1[i]-'a'+1))%mod;
	}
	int sum=0,ans=0;
	for(int i=1;i<=len2;i++)//求子串的哈希值
	{
		sum=(sum*base%mod+(s2[i]-'a'+1))%mod;
	}
	for(int i=1;i+len2-1<=len1;i++)//遍历寻找子串
	{
		if(sum==get(i,i+len2-1)) ans++;
	}
	printf("%d\n",ans);
	return 0;	
}
