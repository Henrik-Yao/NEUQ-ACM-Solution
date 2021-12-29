#include<iostream>
#include<cstring>
using namespace std;

int pow[201][201];
const int maxl=9999999;
void reset(void)
{
	for(int i=0; i<101; i++)
	for(int j=0; j<101; j++)
		pow[i][j]=maxl;
}
int main()
{
	int n, e;
	while(cin>>n)
	{
		cin>>e; 
		reset();
		for(int i=0; i<n; i++)
		{
			
			int beg, k;
			cin>>beg>>k;
			for(int i=0; i<k; i++)
			{
				int end;
				cin>>end;
				pow[beg][end]=1;
				if(beg==end)	pow[beg][end]=0;
			}
		}
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		for(int k=0; k<n; k++)
		if(pow[i][k]+pow[k][j]<pow[i][j])	pow[i][j]=pow[i][k]+pow[k][j];
		for(int i=0; i<e; i++)
		{
			int beg, end;
			cin>>beg>>end;
			if(pow[beg][end]!=maxl)	cout<<pow[beg][end]<<endl;
			else	cout<<"connection impossible"<<endl;
		}
	}
}
