#include<bits/stdc++.h>
using namespace std;
bool ju[20001];
int n,e,xian[51][2];
void bianli(int m)
{
	if(ju[m]) return ;
	ju[m]=1;
	cout<<m<<' ';
	int end=n;
	for(int i=0;i<e;i++)
	{
		if(xian[i][0]==m&&!ju[xian[i][1]]) end=min(xian[i][1],end);
	}
	if(end!=n) bianli(end);
}
int main()
{
	
	cin>>n>>e;
	for(int i=0;i<e;i++) cin>>xian[i][0]>>xian[i][1];
	bianli(0);
	for(int i=1;i<n;i++)
	{
		if(!ju[i]) bianli(i);
	}
	return 0;
}