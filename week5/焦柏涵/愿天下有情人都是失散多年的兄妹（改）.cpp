#include <bits/stdc++.h>
using namespace std;
int da[100001],mo[100001],flag=0;
char sex[100001];
bool vised[100001]={0};
void wufu(int a,int sum)
{
	if(vised[a])
	{
		flag=1;return;
	}
	vised[a]=1;//要放在sum判断前，不然无法录入第五代信息 
	if(sum==5) return;
	if(da[a]!=-1) wufu(da[a],sum+1);
	if(mo[a]!=-1) wufu(mo[a],sum+1);
}
int main()
{
	int n;
	cin>>n;
	memset(da,-1,sizeof(da));
	memset(mo,-1,sizeof(mo)); //必须这么初始化 
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		cin>>sex[a]>>da[a]>>mo[a];
		sex[da[a]]='M';sex[mo[a]]='F';
	}
	cin>>n;
	while(n)
	{
		int a,b;
		cin>>a>>b;
		if(sex[a]==sex[b]) cout<<"Never Mind"<<endl;
		else
		{
			memset(vised,0,sizeof(vised));
			flag=0;
			wufu(a,1);wufu(b,1);
			if(flag==0) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		n--;
	}
	return 0;
}
