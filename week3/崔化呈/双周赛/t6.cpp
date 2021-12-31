#include<bits/stdc++.h>
using namespace std;
bool exist[10];
char a[10],b[10];
bool cmp(char a,char b)
{
	return a<b;
}
void dfs(int len)
{
	if(len==strlen(a))
	{
		for(int i=0;i<len;i++)
		{
			cout<<b[i];
		}
		cout<<endl;
		return;
	}
	for(int i=0;i<strlen(a);i++)
	{
		if(exist[i]==0)
		{
			exist[i]=1;
			b[len]=a[i];
			dfs(len+1);
			exist[i]=0;
		}
	}
}
int main()
{
	cin>>a;
	int slen=strlen(a); 
	sort(a,a+slen,cmp);
	dfs(0);
	return 0;
	
}
