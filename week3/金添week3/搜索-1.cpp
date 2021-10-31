#include <bits/stdc++.h>
using namespace std;
int flag=0;
int city[200],way[200][200];
int m,n,k;
inline void judge(int start,int final)
{
	if(!city[final])
	{
		printf("The city %d is not safe!",final);
		exit(0);
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(city[i]&&way[start][i]&&i!=start)
			{
				if(i==final)
				{				
				   printf("The city %d can arrive safely!",final);
			       exit(0);	   
	            }
				way[i][start]=0;
				way[start][i]=0;
				judge(start,final);
				way[i][start]=1;
				way[start][i]=1;
			}
		}
		printf("The city %d can not arrive safely!",final);
		exit(0);
	}
	
}
int main()
{
	cin>>m>>n>>k;
	for(int i=0;i<n;i++)
	{
		int remp;
		cin>>remp;
		city[remp]=1;
	}
	for(int i=0;i<k;i++)
    {
    	int remp1,remp2;
    	cin>>remp1>>remp2;
    	way[remp1][remp2]=1;
    	way[remp2][remp1]=1;
	}
	int start,final;
	cin>>start>>final;
	judge(start,final);
	return 0;
}
