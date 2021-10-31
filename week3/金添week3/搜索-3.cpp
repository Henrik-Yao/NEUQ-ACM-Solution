#include <bits/stdc++.h>
using namespace std;
int zone[21][21];//地图上每一个节点周围八个点的地雷个数，即最后要输出的值 
int mine[21][21];//地图上每一个节点的地雷个数
int flag=0;
int n,m,k,l;
void search(int remp1,int remp2)
{
	if(!(remp1>=0&&remp1<n&&remp2>=0&&remp2<m))
	return;//到达雷区边界，停止，开始回溯重置 
	zone[remp1][remp2]=0;   
	for(int i1=-1;i1<=1;i1++)
	{
		for(int j1=-1;j1<=1;j1++)
		{
			if(!(i1==0&&j1==0))
			{
				if((remp1+i1>=0&&remp1+i1<n&&remp2+j1>=0&&remp2+j1<m)&&mine[remp1+i1][remp2+j1])
				{
				    zone[remp1][remp2]++;
			    }	 
			}
		}
	}
	if(zone[remp1][remp2])
	return;//若该点附近有地雷，则返回
	else//若该点周围无地雷，则继续寻找 
	{
		for(int i2=-1;i2<=1;i2++)
		{
			for(int j2=-1;j2<=1;j2++)
			{
		     	if(!(i2==0&&j2==0))
				{
					if((remp1+i2>=0&&remp1+i2<n&&remp2+j2>=0&&remp2+j2<m)&&zone[remp1+i2][remp2+j2]==-1)
					{
				    	 search(remp1+i2,remp2+j2);
			   	 	}	 
				}	    	
    		}
    	}
	}
}
int main()
{
	memset(zone,-1,sizeof(zone));
	cin>>n>>m>>k>>l;
	for(int i=0;i<k;i++)
	{
		int remp1,remp2;
		cin>>remp1>>remp2;
		mine[remp1][remp2]=1;  
	}
	for(int h=0;h<l;h++)
	{
		int remp1,remp2;
		cin>>remp1>>remp2;
		if (zone[remp1][remp2] >= 0)continue;//如果该点已打开，无视该请求 
		if(mine[remp1][remp2])//若该点为地雷，则直接游戏结束 
	    {
	        cout<<"You lose"<<endl;
	    	break;
		}
		search(remp1,remp2);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<zone[i][j]<<" ";
			} 
			cout<<endl;
		}
	int paichu=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(zone[i][j]==-1)
			paichu++;
		}
    }
	if(paichu==k)
	{
	cout<<"You win"<<endl;
	break;
    }
	
	cout<<endl; 
	
	}
	
	return 0;	
}
