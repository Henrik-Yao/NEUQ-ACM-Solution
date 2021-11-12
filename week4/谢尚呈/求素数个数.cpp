#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

const int max_l=10000001;

int num[max_l];
bool has[max_l];
int to_nu=0;


void solve(int x)
{
	for(int i=2; i<=x; i++)
	{
		if(has[i]);
		else
		{
			num[to_nu]=i;
			to_nu+=1;
			has[i]=true;
		}
		for(int j=0; j<to_nu; j++)
		{
			if(i*num[j]>x)	break;
			has[i*num[j]]=true;
			if(i%num[j]==0)	break;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	solve(n);
	//for(int i=0; i<=to_nu; i++)	cout<<num[i]<<" ";
	//cout<<endl;
	cout<<to_nu;
	return 0;
}
