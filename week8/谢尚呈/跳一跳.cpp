#include<cstdio>
using namespace std;

int end;
int road[1000000];

int solve(int it)
{
	if(it+road[it]>=end)	return 1;
	
	int max1=0;
	int max=it+road[it];
	
	for(int i=it+1; i<=it+road[it]; i++)
	if(road[i]>=road[max] && road[i]+i-it>road[it])
		max=i;
		
	max1=road[max]+max;
	
   for(int i=max; i<=it+road[it]; i++)
	{
		if(road[i]+i>max1)
		{
			max1=road[i]+i;
			max=i;
		}
	}
	
	return(solve(max)+1);
}

int main()
{
	scanf("%d", &end);
	end-=1;
	for(int i=0; i<=end; i++)	scanf("%d", &road[i]);
	int bestr=solve(0);
	printf("%d", bestr);
	return 0;
}
