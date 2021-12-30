#include<stdio.h>
#include<iostream>
#define max 1000
using namespace std;

int n, e;
double **pow;

void dij(int beg, int end)		//pow:记录自下标一至下标二的路的权重 
{
    double *near=new double[n];	//near:记录起点至下标最短路 
    int *pres=new int[n];		//pres:记录最短路中下标的前驱 
	bool *sea=new bool[n];		//sea:记录下标的节点是否被搜索过
    
    int k;
    double min, inf=200;
    int t_beg=beg-1;
    
    for(int i=0; i<n; i++)
    {
        near[i]=pow[t_beg][i];
        if(near[i]!=max)	pres[i]=beg;
        else	pres[i]=0;
    }
    
    for(int i=0; i<n; i++)    sea[i]=0;
    sea[t_beg]=1;
    near[t_beg]=0;
    
    for(int i=0; i<n-1; i++)
    {
        min=inf;
        for(int j=0;j<n;j++)
        if((!sea[j])&&(near[j]<min))
        {
            min=near[j];
            k=j;
    	}
        sea[k]=1;
        
        for(int j=0;j<n;j++)
        if((!sea[j])&&(near[j]>near[k]+pow[k][j]))
        {
            near[j]=near[k]+pow[k][j];
            pres[j]=k+1;
        }
    }
    
    int t_end=end-1, pre=pres[t_end], times=0;
    int *roads=new int[n];
    while(pre!=0)
    {
        roads[times]=pre;
        times++;
		pre=pres[pre-1];
    }
    
    cout<<beg-1<<"-->";
    for(k=times-2; k>=0; k--)	cout<<roads[k]-1<<"-->";
    if(near[t_end]!=max)	cout<<t_end<<":"<<near[t_end];
    
    delete near;
    delete pres;
    delete sea;
    return;
}

int main()
{
    cin>>n>>e;
    pow=new double*[n];
    for(int i=0; i<n; i++)	pow[i]=new double[n];
    
    for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
        pow[i][j]=max;
        
    for(int i=0; i<e/2; i++)
    {
    	int fir, sec;
    	double pows;
        cin>>fir>>sec>>pows;
        pow[fir][sec]=pows;
        pow[sec][fir]=pows;
    }
    
    int beg, end;
    cin>>beg>>end;
    dij(beg+1, end+1);
    
    for(int i=0; i<n; i++)	delete pow[i];
    delete pow;
    return 0;
}
