#include<iostream>
#include<cstdio>
using namespace std;

long long org[1000003];
//long long plu[1000000];
//int add[1000000];

inline int lowbit(int x)
{
	return (x)&(-x);
}

void redata(int ind, int vul, int tot)
{
	for(int i=ind; i<=tot; i+=lowbit(i))	org[i]+=vul;
	return;
}

long long ask(int ind)
{
	long long total=0;
	for(ind=ind; ind>0; ind-=lowbit(ind))	total+=org[ind];
	return total;
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; i++)
	{
		int temp;
		scanf("%d", &temp);
		redata(i, temp, n);
	}
	for(int i=0; i<q; i++)
	{
		int sign, left, right;
		cin>>sign>>left>>right;
		if(sign==1)
			redata(left, right, n);
		else
			cout<<ask(right)-ask(left-1)<<endl;
	}
	return 0;
}
