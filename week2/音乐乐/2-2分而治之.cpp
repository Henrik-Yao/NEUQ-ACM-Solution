#include<bits/stdc++.h>
using namespace std;

int N,M,K;
int t[10010];
struct road
{
	int first;
	int second;
};
road a[10010];

int main()
{
	cin>>N>>M;
	int i,j;
	for(i=0;i<M;i++)
	{
		cin>>a[i].first;
		cin>>a[i].second;
	}
	cin>>K;
	while(K--)
	{
		memset(t,0,sizeof(t));
		int Np,c;
		cin>>Np;
		for(i=0;i<Np;i++)
		{
			cin>>c;
			t[c]=1;
		}
		int flag=0;
		for(j=0;j<M;j++)
		{
			if(!t[a[j].first]&&!t[a[j].second])
			{
				
				flag=1;
				break;
			}
		}
		if(flag)
		cout << "NO" << endl; 
		else
		cout << "YES" << endl;
    }	
		return 0;
}
