# include<bits/stdc++.h>
using namespace std;
int n,m,k,l,a,b;
struct P{
    int tot;
    int num; 
};
struct P ditu[30][30];
int dx[]={0,1,-1,0,0,1,1,-1,-1},dy[]={0,0,0,1,-1,1,-1,1,-1};
void F(int x,int y){
    int newx[]={0,1,-1,0,0,1,1,-1,-1},newy[]={0,0,0,1,-1,1,-1,1,-1};
    for(int i=1;i<=8;i++){
     int xx=x+newx[i];
     int yy=y+newy[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m&&ditu[xx][yy].num!=-1)ditu[xx][yy].num++; 
    }
}
void dfs(int x,int y){
    ditu[x][y].tot=1;
    for(int i=1;i<=8;i++){
    	int xx=x+dx[i];
    	int yy=y+dy[i];
    	if(xx>=0&&yy>=0&&xx<n&&yy<m&&ditu[xx][yy].num!=-1&&ditu[xx][yy].tot!=1){
    		if(ditu[xx][yy].num!=0)ditu[xx][yy].tot=1; 
    		else dfs(xx,yy);
		}
	}
}
int main(){
    cin>>n>>m>>k>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ditu[i][j].tot=-1;
            ditu[i][j].num=0;
        }
    }
    for(int i=0;i<k;i++){
        cin>>a>>b;
        ditu[a][b].num=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ditu[i][j].num==-1)F(i,j);
        }
    }
    while(l--){
        int flag=1;
        cin>>a>>b;
        if(ditu[a][b].tot==1)continue; 
         if(ditu[a][b].num==-1){
            cout<<"You lose"<<endl;
                return 0;
        }
        else if(ditu[a][b].num==0){
            dfs(a,b); 
        }
        else  ditu[a][b].tot=1; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ditu[i][j].tot==-1)cout<<ditu[i][j].tot<<" ";
                else cout<<ditu[i][j].num<<" "; 
                if(ditu[i][j].tot==-1&&ditu[i][j].num!=-1)flag=0;
            }
            cout<<endl;
        }
        if(flag==1){
		cout<<"You win"<<endl;
		return 0;
	}
        cout<<endl;
    }
    return 0;
}
