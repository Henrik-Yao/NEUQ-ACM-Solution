#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
struct node{
	int x,y;
}Node;
int xx[4]={0,0,-1,1};
int yy[4]={-1,1,0,0};
int n,m;
int bk[maxn][maxn]={0};
int room[maxn][maxn];
bool pan(int x,int y){
	if(x>=n || x<0 || y>=m ||y<0) return false;
	if(bk[x][y] || room[x][y] == 0 ) return false;
	return true;
} 
void BFS(int x,int y){
	queue<node> q;
	Node.x=x,Node.y=y;
	q.push(Node);
	bk[x][y] = 1;
	while(!q.empty()){
		node top=q.front();
	    q.pop();
	for(int i=0;i<4;i++){
		int newx=top.x+xx[i],newy=top.y+yy[i];
		if(pan(newx,newy)){
			Node.x=newx,Node.y=newy;
		    q.push(Node);
		    bk[newx][newy]=1;
		}
	}
	
	}
}
int main()
{
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<n;i++){
    	getchar();
    	for(int j=0;j<m;j++){
    		cin>>room[i][j];
		}
	}
	 for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(pan(i,j)){
    		  ans++;
			 	BFS(i,j);
			}
		}
	}
	cout<<ans;
    return 0;
}



