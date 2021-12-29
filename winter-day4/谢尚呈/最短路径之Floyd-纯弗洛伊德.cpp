#include<iostream>
using namespace std;

double pow[101][101];		//从下标一到下标二的路径权值 
int path[101][101];		//从下标一到下标二首先经过的点

void speck(int beg, int end)
{
	if(beg==101||end==101)	return;
	if(path[beg][end]!=101)
	{
		speck(beg, path[beg][end]);
		speck(path[beg][end], end);
	}
	else cout<<"->"<<end;
	return;
}

void tell(int beg, int end)
{
	if(beg==end)
	{
		cout<<beg<<"->"<<end<<":0";
		return;
	}
	if(pow[beg][end]==9999)
	{
		cout<<beg<<"->"<<end<<":-1";
		return;
	}
	int now=beg;
	
	cout<<now;
	/*
	while(path[now][end]!=101)
	{
		now=path[now][end];
		cout<<"->"<<now;
	}
	*/
	speck(now, end);
	cout<<":"<<pow[beg][end];
	return;
}

int main()
{
	for(int i=0; i<101; i++)
	for(int j=0; j<101; j++)
	{
		pow[i][j]=9999;
		path[i][j]=101;
	}
	
	for(int i=0; i<101; i++)
	{
		pow[i][i]=0;
		path[i][i]=0;
	}
	
	int n, m;
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		int beg, end;
		double pows;
		cin>>beg>>end>>pows;
		pow[beg][end]=pows;
	}
	/*
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		cout<<"pow["<<i<<"]["<<j<<"]="<<pow[i][j]<<endl;
	*/
	for(int k=0; k<n; k++)
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	if(pow[i][k]+pow[k][j]<pow[i][j])
	{
		/*
		cout<<"pow["<<i<<"]["<<k<<"]="<<pow[i][k]<<" +";
		cout<<"pow["<<k<<"]["<<j<<"]="<<pow[k][j]<<" is less than ";
		cout<<"pow["<<i<<"]["<<j<<"]="<<pow[i][j]<<endl;
		cout<<"set path["<<i<<"]["<<j<<"] as "<<k<<endl;
		*/
		pow[i][j]=pow[i][k]+pow[k][j];
		path[i][j]=k;
	}
	
	for(int i=0; i<2; i++)
	{
		int beg, end;
		cin>>beg>>end;
		tell(beg, end);
		cout<<endl;
	}
	
	int beg=0, end=0;
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	{
		if(pow[i][j]!=9999)
		if((pow[beg][end]==9999)||(pow[beg][end]<pow[i][j]))
		{
			beg=i;
			end=j;
		}
	}
	tell(beg, end);
	
	return 0;
 } 
