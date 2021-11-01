#include<bits/stdc++.h>
using namespace std;
int n, m, k, l;
int open=0;
int mine[22][22];
bool book[22][22]={false};
int lr[8]={-1,-1,-1,0,1,1,1,0};
int ud[8]={1,0,-1,-1,-1,0,1,1};
void dfs(int x, int y){
	if(book[x][y] || x<0 || x>=n || y<0 || y>=m) return;
	book[x][y]=true;
	open++;
	int round=0;
	for(int i=0;i<8;i++){
		int f=x+ud[i],s=y+lr[i];
		if(f>=0 && f<n && s>=0 && s<m && mine[f][s]==-2) round++;
	}
	if(round==0){
		mine[x][y]=0;
		for(int i=0;i<8;i++){
			dfs(x+ud[i],y+lr[i]);
		}
	}
	else{
		mine[x][y]=round;
		return;
	}
}
int main(){
	cin>>n>>m>>k>>l;
	int num=n*m-k;
	memset(mine,-1,sizeof(mine));
	int i,j,x,y;
	for(i=0;i<k;i++){
		cin>>x>>y;
		mine[x][y]=-2;
	} 
	for(int k=0;k<l;k++){
		cin>>x>>y;
		if(mine[x][y]==-2){
			cout<<"You lose";
			break;
		}
		if(mine[x][y]!=-1) continue;
		dfs(x,y);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(mine[i][j]==-2) cout<<-1<<" ";
				else cout<<mine[i][j]<<" ";
			}
			cout<<endl;
		}
		if(open==num){
			cout<<"You win"<<endl;
			break;
		}
		cout<<endl;
	}
	return 0;
}
