#include<bits/stdc++.h>
using namespace std;
int c[1600][1600];
void Prim(int n,int c[ ][1600])
{
    int  lowcost[1600];
    int closet[1600];
    bool foot[n+1];
    memset(lowcost,0,sizeof(lowcost));
    memset(closet,0,sizeof(closet));
    foot[1]=true;
    for(int i=2;i<=n;i++)
	{
        foot[i]=false;
        closet[i]=1;
        lowcost[i]=c[1][i];
    }
    for(int i=1;i<n;i++)
	{
        int  min=99999;
        int j=1;
        for(int k=2;k<=n;k++)
		{
            if((lowcost[k]<min)&&(foot[k]==false))
			{
                min=lowcost[k];
                j=k;
            }
        }
        
        foot[j]=true;
        for(int k=2;k<=n;k++)
		{
            if((c[j][k]<lowcost[k])&&(foot[k]==false)){
                lowcost[k]=c[j][k];
                closet[k]=j;
            }
        }
    }
    int flag=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(foot[i]==false) flag=-1;
		sum+=lowcost[i];
	}
	if(flag==-1)
	cout<<"There is no minimum spanning tree."<<endl;
	else
	cout<<sum<<endl;
}
int main()
{
    int n,e;
    while(cin>>n>>e)
    {
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
		{
            c[i][j]=99999;
        }
    }
    int xi,yi,val;
    for(int i=1;i<=e;i++)
	{
        cin>>xi>>yi>>val;
        c[xi][yi]=val;
        c[yi][xi]=val;
    }
    Prim(n,c);
	}
    return 0;
}
