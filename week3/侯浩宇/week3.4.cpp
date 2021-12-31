#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,b[1001][1001],g,sc[100001];
char a1[1001][1001];
void ddd(int x1,int y1,int z,int xc){
	if(x1<0||x1>=n||y1<0||y1>=n||b[x1][y1]!=(-1)||a1[x1][y1]-'0'!=z) return;
    b[x1][y1]=xc;
	sc[xc]++;  
	ddd(x1-1,y1,!z,xc); 
	ddd(x1+1,y1,!z,xc);
	ddd(x1,y1-1,!z,xc);
	ddd(x1,y1+1,!z,xc);
}
int main(){
	memset(b,-1,sizeof(b));
	cin>>n>>m;
	for(int i=0;i<=n-1;i++)
	for(int j=0;j<=n-1;j++)
	cin>>a1[i][j];
	for(int i=0;i<=m-1;i++)
	{
		cin>>x>>y;
		x--;y--;
		if(b[x][y]==-1) ddd(x,y,a1[x][y]-'0',i);
		else sc[i]=sc[b[x][y]];	 
	}
	for(int i=0;i<=m-1;i++) cout<<sc[i]<<endl;
	return 0;
}
