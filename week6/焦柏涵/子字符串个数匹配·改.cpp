#include <bits/stdc++.h>
using namespace std;
int nex[10001],sum=0;
string t[10001],p;
void pipei(string p)//部分匹配值 
{
	int i=0,j=-1;
	nex[0]=-1;
	while(i<p.size())
	{
		if(j==-1||p[i]==p[j])
		{
			i++;j++;
			nex[i]=j;
		}
		else j=nex[j];
	}
}
void kmp(string t,string p)//kmp算法 
{
	int i=0,j=0;
	while(i<t.size())
	{
		if(j==-1||t[i]==p[j])
		{
			i++;j++;
		}
		else j=nex[j];
		if(j==p.size())
		{
			sum++;break;
		}
	}
}
int main()
{
	int i=0;
	char x;
	while(x=getchar())
	{
		if(x=='\n') break;//结束条件 
		if(x>='a'&&x<='z') t[i]+=x;
		else if(x>='A'&&x<='Z') t[i]+=x+32;
		else if(t[i]==" ") continue;
		else i++;
	}
	i++;//break后少一个i 
	cin>>p;
	for(int j=0;j<p.size();j++)
		if(p[j]>='A'&&p[j]<='Z') p[j]=p[j]+32;
	pipei(p);
	while(i--)
	{
		if(t[i]==" ") continue;
		kmp(t[i],p);
	}
	cout<<sum;
	return 0;
}
