#include<iostream>
using namespace std;
int mark[100];	//第一条队列 
int mem[100];	//第二条及以后的队列，只记录最后一个驶入列车的序号 
int ori[100];	//原本的排入顺序 
int main()
{
	int n;
	cin>>n;
	int lon=0, th=0;//第一条队列中第一个空位下标，其他队列的数目 
	for(int i=0; i<n; i++)
	{
		int it;
		cin>>it;
		if(lon==0)
		{
			mark[lon]=it;
			lon+=1;
			continue;
		}
		int min=-1;
		for(int j=0; j<th; j++)
		{
			if(mark[lon-1]>it)
				if(min==-1)
					if(mem[j]<mark[lon-1]&&mem[j]>it)	min=j;
					else;
				else
					if(mem[j]<mem[min]&&mem[j]>it)	min=j;
					else;
			else
				if(min==-1)
					if(mem[j]>it)	min=j;
					else;
				else
					if(mem[j]<mem[min]&&mem[j]>it)	min=j;
					else;
		}
		if(min==-1)
		if(mark[lon-1]>it)
		{
			mark[lon]=it;
			lon+=1;
			continue;
		}
		else
		{
			mem[th]=it;
			th+=1;
			//cout<<it<<"开了一条新铁轨"<<endl;
			continue;
		}
		else
		{
			mem[min]=it;
			continue;
		}
	}
	for(int i=0; i<lon; i++)
	{
		cout<<mark[i];
		if(i!=lon-1)	cout<<" ";
	}
	cout<<endl;
	cout<<th+1;
	return 0;
}
