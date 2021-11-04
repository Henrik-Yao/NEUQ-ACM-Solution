#include <iostream>
using namespace std;
int a[26][26],boom[26][26],opened[26][26];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,-1,-1,-1,0,1,1,1};
int boomnum=0;
bool losethegame=false;
bool testthewinstage(){
	for(int i=0;i<=21;i++){
		for(int j=0;j<=21;j++){
			if(a[i][j]==-1&&boom[i][j]!=1) return false;
		}
	}
	return true;
}
void Open(int x,int y){
	if(a[x][y]==-1){
		if(boom[x][y]==1) {losethegame=true;return;}
		int nextx,nexty;
		boomnum=0;
		for(int aaa=0;aaa<8;aaa++){
			nextx=x+dx[aaa];
			nexty=y+dy[aaa];
			if(nextx>=0&&nextx<=20&&nexty>=0&&nexty<=20){
				if(a[nextx][nexty]==-1&&boom[nextx][nexty]==1){
					boomnum++;
				}
			}
		}
		a[x][y]=boomnum;
		if(boomnum==0){
			for(int k=0;k<8;k++){
				nextx=x+dx[k];
				nexty=y+dy[k];
				if(nextx>=0&&nextx<=20&&nexty>=0&&nexty<=20){
				if(a[nextx][nexty]==-1&&boom[nextx][nexty]==0){
					Open(nextx,nexty);
				}
			}

			}
		}
		return;
	}
}
int main(){
	int n,m,k,l;
	cin >> n >> m >> k >> l;
	for(int i=0;i<=25;i++) for(int j=0;j<=25;j++) a[i][j]=-2;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=-1;
	int i,j;
	for(int abc=1;abc<=k;abc++){
		cin >> i >> j;
		i++;
		j++;
		boom[i][j]=1;
	}
	for(int abc=1;abc<=l;abc++){
		cin >> i >> j;
		i++;
		j++;
        if(a[i][j]!=-1) continue;
		Open(i,j);
		if(losethegame==true) {cout << "You lose";break;}
        for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cout <<a[i][j]<< " ";
			cout << endl;
		}
		if(testthewinstage()==true) {cout << "You win";}
		cout << endl;
	}
	return 0;
}