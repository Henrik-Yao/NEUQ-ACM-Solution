#include<bits/stdc++.h>
using namespace std;
int a[30][30];//show[20][20];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int n,m;
void fa(int x,int y);
int main(){
	int k,l,i;
	int s,ss;
	cin>>n>>m>>k>>l;
	for(s=0;s<n;s++){
		for(ss=0;ss<m;ss++){
			a[s][ss]=-1;
			//show[n][m]=-1;
		}
	}
	int d1,d2;
	for(i=0;i<k;i++){
		cin>>d1>>d2;
		a[d1][d2]=-2;
	}
	int aa,b;
	for(i=0;i<l;i++)
	{	
		cin>>aa>>b;
		if(a[aa][b]>=0)continue;
		if(a[aa][b]==-2){
			cout<<"You lose"<<endl;
			return 0;
		}
			//a[aa][b]=0;
			fa(aa,b);
			for(s=0;s<n;s++){
				for(ss=0;ss<m;ss++){
					if(a[s][ss]==-2)cout<<"-1"<<" ";
					else cout<<a[s][ss]<<" ";
				}
				cout<<endl;
			}
			int bz=0;
			for(s=0;s<n;s++){
				for(ss=0;ss<m;ss++){
					if(a[s][ss]==-1){
						bz=1;
						break;
					}
				}
				if(bz==1)break;
			}
			if(bz==0){
				cout<<"You win"<<endl;
				return 0;
			}
			cout<<endl;
	}
	return 0;
}
void fa(int x,int y){
	a[x][y]=0;
	for(int i=0;i<8;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<0||xx>=n||yy<0||yy>=m)continue;
		else if(a[xx][yy]==-2)a[x][y]++;
		//if(a[xx][yy]==-1&&a[x][y]==0)fa(xx,yy);
	}
	for(int i=0;i<8;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(a[xx][yy]==-1&&a[x][y]==0)fa(xx,yy);
	}
}  
