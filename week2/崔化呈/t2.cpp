#include<bits/stdc++.h>
using namespace std;
struct r
{
	int s;
	int e;
};
int main()
{
	int cn,rn;
	cin>>cn>>rn;
	r r1[rn];
	for(int i=0;i<rn;i++)
	{
		cin>>r1[i].s>>r1[i].e;
	}
	int wn;
	cin>>wn;
	int c[10050];
	
	for(int i=0;i<wn;i++)
	{
		memset(c,0,sizeof(c));
		int np;
		cin>>np;
		for(int j=0;j<np;j++)
		{
			int cg;
			cin>>cg;
			c[cg]=1;
		}
		int flag=1;
		for(int j=0;j<rn;j++)
		{
			if(c[r1[j].s]||c[r1[j].e]){}
			else
			{
				flag=0;break;	
			}
			
		}
		if(flag){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
	return 0;
}
