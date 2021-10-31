#include<iostream>
#include<string.h>
using namespace std;
int n,m,k,l;
int map[21][21];
void f(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return;
	map[x][y]=0;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(map[x+i][y+j]==-2)
			++map[x][y];
		}
	}
	if(map[x][y]>0) return;
		for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(map[x+i][y+j]==-1) 
			f(x+i,y+j);
		}
	}
}
int main(){
	cin>>n>>m>>k>>l;
	int x,y;
	memset(map,-1,sizeof(map));
	for(int i=0;i<k;i++){
		cin>>x>>y;
		map[x][y]=-2;
	}
	for(int i=0;i<l;i++){
		cin>>x>>y;
		int count=0;
		if(map[x][y]>=0) continue;
		else if(map[x][y]==-2){
			cout<<"You lose"<<endl;
			break;
		}
		else {
			f(x,y);
			for(int i1=0;i1<n;i1++){
		for(int j1=0;j1<m;j1++){
			if(map[i1][j1]>=0) cout<<map[i1][j1]<<" ";
			else{
				cout<<-1<<" ";
				++count;
			}
		}
		cout<<endl;
	}
		if(count==k){
		cout<<"You win"<<endl;
		break;
	}
		}
	cout<<endl;
}
}
