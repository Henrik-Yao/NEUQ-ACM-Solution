#include<iostream>
using namespace std;

int pow[101][101];
void reset(void)
{
	for(int i=0; i<101; i++)
	for(int j=0; j<101; j++)
		pow[i][j]=999999;
}
int main()
{
	int n, e;
	while(cin>>n)
	{
		cin>>e; reset();
		for(int i=0; i<e; i++)
		{
			int beg, end;
			cin>>beg>>end;
			cin>>pow[beg][end];
			if(beg==end)	pow[beg][end]=0;
			else	pow[end][beg]=pow[beg][end];
		}
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		for(int k=0; k<n; k++)
		if(pow[i][k]+pow[k][j]<pow[i][j])	pow[i][j]=pow[i][k]+pow[k][j];
		int min=0; long long total=0;
		for(int i=0; i<n; i++)
		{
			long long tot=0;
			for(int j=0; j<n; j++)	if(i!=j)	tot+=pow[i][j];
			if(min==i)	total=tot;
			else	if(tot<total)	min=i, total=tot;
		}
		cout<<min<<endl;
	}
}
