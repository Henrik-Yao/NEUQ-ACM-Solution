#include<iostream>
using namespace std;
int round[10000000];
int haspe[1000];

int main()
{
	int n, m, q;
	int total=0;
	cin>>n>>m>>q;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		if(round[a])
		{
			round[b]=round[a];
			haspe[round[a]]+=1;
			continue;
		}
		else if(round[b])
		{
			round[a]=round[b];
			haspe[round[b]]+=1;
			continue;
		}
		else
		{
			total+=1;
			round[a]=round[b]=total;
			haspe[total]+=2;
		}
	}
	for(int i=0; i<q; i++)
	{
		int a, b;
		cin>>a>>b;
		if(round[a]&&round[b])
		if(round[a]==round[b])
		{
			cout<<"In the same gang."<<endl;
			continue;
		}
		cout<<"In different gangs."<<endl;
	}
	int sum=0;
	for(int i=1; i<=total; i++)	sum+=haspe[i];
	total+=n-sum;
	cout<<total;
	return 0;
}
