#include<bits/stdc++.h>
using namespace std;
const int maxn=100;//字符串长度最大值为maxn
string user[1000],paw[1000],paw2[1000],sha;//paw存哈希对应的四位数,paw2存未转换的密码
int a[5]={};
map<string,int>login;//存用户名对应的序号
void cut(int len)//分为四部分
{
	int t=len/4,m=len%4;
	for(int i=1;i<=4;i++)
	{
		a[i]=a[i-1]+t;
		if(m>0)
		{
			a[i]++;
			m--;
		}
	}
}
int she1(char x)//字符转为36进制数字
{
	if(x>='A'&&x<='Z') return x-55;
	else if(x>='a'&&x<='z') return x-87;
	else if(x>='0'&&x<='9') return x-48;
}
char she2(int x)
{
	if(x>=0&&x<=9) return x+48;//转为字符数字
	else if(x>=10&&x<36) return x+87;//换为小写
}
void ha(string s,int len)//返回字符串的哈希值
{
	cut(len);
	int t=0;//每块数字相加
	for(int i=1;i<=4;i++)//处理四部分
	{
		t=0;
		for(int j=a[i-1];j<a[i];j++)
		{
			t+=she1(s[j]);
		}
		sha[i-1]=she2(t%36);
	}
}
int main()
{
	int n,sum=0,len;
	string un,pw;
	char x;
	cin>>n;
	while(n--)
	{
		cin>>x>>un>>pw;
		len=pw.size();
		if(x=='R')//注册
		{
			int f=0;
			if(login[un])
			{
				f=1;//已被注册
				puts("Repeated!");
			}
			if(f==0)//注册成功
			{
		 	    sum++;
		 	    paw2[sum]=pw;//存原始密码
		 	    login[un]=sum;//用户名对应序号
		 	    ha(pw,len);
		 	    for(int i=0;i<4;i++)//存密码
		 	    {
		 	    	paw[sum]+=sha[i];
				}
				puts("Signed!");
			}
		}
		else if(x=='L')//登录
		{	
		    int k=0,f=0;
		    string pwx;//存转换后的密码用于比较
		    if(login[un])//查看是否存在用户
		    {
		    	f=1;
		    	k=login[un];
			}
			ha(pw,len);//转换
		 	for(int i=0;i<4;i++)
		 	{
		 	    pwx+=sha[i];
			}
			if(paw[k]!=pwx||f==0) puts("Failed!");
			else if(paw[k]==pwx&&paw2[k]==pw&&f==1) puts("Success!");
			else if(paw[k]==pwx&&paw2[k]!=pw&&f==1) puts("Attention!");
		}
	}
	return 0;	
}
