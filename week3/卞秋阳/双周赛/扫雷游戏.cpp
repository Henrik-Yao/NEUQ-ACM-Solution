#include<iostream>
using namespace std;
int xv[8]={0,0,1,1,1,-1,-1,-1};
int yv[8]={-1,1,-1,0,1,-1,0,1};
int wyj[110][110],bo[110][110];
int vis[110][110],map1[110][110];
int n,m,k,l,num;
bool pd(int x,int y);
int get(int x,int y);	
void fuc(int x,int y)
{   vis[x][y]=1;
	num++;
	if(pd(x,y)==1){
     wyj[x][y]=map1[x][y];
	for(int i=0;i<8;i++){
			int x1,y1;
			x1=x+xv[i];
			y1=y+yv[i];
			if(x1<0||x1>=n||y1<0||y1>=m||vis[x1][y1]) continue; 
			fuc(x1,y1);
		}
		return; 
	}
	else{
		wyj[x][y]=map1[x][y];
		return;
	}
	
}
int main(){
	cin>>n;
	cin>>m;
	cin>>k;
	cin>>l;
	for(int i=0;i<n;i++){
	   for(int j=0;j<m;j++){
		  wyj[i][j]=-1;
           }
	   }
	for(int i=1;i<=k;i++){
		int x1,y1;
		cin>>x1>>y1;
		bo[x1][y1]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		{map1[i][j]=get(i,j);
		}
	}
	while(l--){
		int xi,yi;
		cin>>xi>>yi;
		if(bo[xi][yi]==1){
			cout<<"You lose";break;
		}
		if(wyj[xi][yi]!=-1) continue;
		if(wyj[xi][yi]==-1){ 
			fuc(xi,yi);
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout<<wyj[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		if(n*m-k==num){
			puts("You win");
			return 0;
		}
		cout<<endl;
	}
	return 0;
}
int get(int x,int y){
	int res=0;
	for(int i=0;i<8;i++){
		int xi,yi;
		xi=x+xv[i];
		yi=y+yv[i];
		if(xi<0||xi>=n||yi<0||yi>=m) continue;
		if(bo[xi][yi]==1) res++;
	}
	return res;
}
bool pd(int x,int y){
	int t=0;
	for(int i=0;i<8;i++){
		int b,c;
		b=x+xv[i];
		c=y+yv[i];
		if(b<0||b>=n||c<0||c>=m) continue;
		if(bo[b][c]==1) t=1;
	}
	if(t==1){
		return 0;
	}
	else return 1;
}
