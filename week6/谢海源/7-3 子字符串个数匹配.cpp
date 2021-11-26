#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;//字符串长度最大值为maxn
const int base=1776840;//进制
const int mod = 1e9 + 7;
char s1[maxn],s2[maxn],sx[maxn];
int p[maxn], ha[maxn];
bool check(char x)//检查是否为字母
{
	if(x>='a'&&x<='z'||x>='A'&&x<='Z') return 1;
	else return 0;
}
int get(int l,int r)//求子串的哈希值
{
    return (ha[r] - ha[l - 1]*p[r-l+1]%mod + mod)%mod;
}
void init()//预处理
{
	p[0]=1;
	for(int i=1;i<=maxn;i++)
	{
		p[i]=p[i-1]*base%mod;
	}
}
signed main()
{
	init();//预处理
	cin.getline(s1+1,maxn);
	cin.getline(s2+1,maxn);//B字符
	int  len1=strlen(s1+1),len2=strlen(s2+1);
	for(int i=1;i<=len1;i++)//处理大写字母
	{
		if(s1[i]>='A'&&s1[i]<='Z') s1[i]+=32;
	}
	for(int i=1;i<=len2;i++)//处理大写字母
	{
		if(s2[i]>='A'&&s2[i]<='Z') s2[i]+=32;
	}
	int sum=0,ans=0;
	for(int i=1;i<=len2;i++)//求B串的哈希值
	{
		sum=(sum*base%mod+(s2[i]-'a'+1))%mod;
	}
	int l,r,f,i=1;
	while(i<=len1)
	{
		f=0,r=0;
		while(check(s1[i])==1)
		{
			if(f==0)
			{
				f=1;
				l=i;//子串开始点
			}
			i++;
			if(check(s1[i])==0&&i-l>=len2)
			{
				r=i-1;//子串右端
				ha[l-1]=0;
				for(int j=l;j<=r;j++)//文章串哈希
	            {
	               	ha[j]=(ha[j-1]*base%mod+(s1[j]-'a'+1))%mod;
	            }
				for(int j=l;j+len2-1<=r;j++)
			    {
			     	if(sum==get(j,j+len2-1))
			     	{
			     		ans++;
			     		break;
					}
			    }
			}
		}
		i++;
	}
	printf("%d",ans);
	return 0;	
}