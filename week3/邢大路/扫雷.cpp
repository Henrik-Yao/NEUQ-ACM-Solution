# include<bits/stdc++.h>
using namespace std;
int n,m,k,l,a,b;
struct P{
    int tot;//状态  -1为未搜索过，搜到了就改为1 
    int num;//-1代表是地雷，其余代表周围地雷数 
};
struct P ditu[30][30];
int dx[]={0,1,-1,0,0,1,1,-1,-1},dy[]={0,0,0,1,-1,1,-1,1,-1};
void F(int x,int y){
    int newx[]={0,1,-1,0,0,1,1,-1,-1},newy[]={0,0,0,1,-1,1,-1,1,-1};
    for(int i=1;i<=8;i++){
     int xx=x+newx[i];
     int yy=y+newy[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m&&ditu[xx][yy].num!=-1)ditu[xx][yy].num++; // 地雷周围格子中非地雷的格子num加一 
    }
}
void dfs(int x,int y){
    ditu[x][y].tot=1;
    for(int i=1;i<=8;i++){
    	int xx=x+dx[i];
    	int yy=y+dy[i];
    	if(xx>=0&&yy>=0&&xx<n&&yy<m&&ditu[xx][yy].num!=-1&&ditu[xx][yy].tot!=1){
    		if(ditu[xx][yy].num!=0)ditu[xx][yy].tot=1;//地雷周围 停止搜索 
    		else dfs(xx,yy);//非地雷周围 搜索继续 
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
    }//状态初始化
    for(int i=0;i<k;i++){
        cin>>a>>b;
        ditu[a][b].num=-1;
    }// 地雷的num赋为1
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ditu[i][j].num==-1)F(i,j);
        }
    }//每个地雷周围的格子的num加1
    while(l--){
        int flag=1;
        cin>>a>>b;
        if(ditu[a][b].tot==1)continue; //无效的点击无视
         if(ditu[a][b].num==-1){
            cout<<"You lose"<<endl;//踩雷了
                return 0;
        }
        else if(ditu[a][b].num==0){
            dfs(a,b); //正常情况 点到非炸弹周围空格 开始搜索，标记所有能走到的
        }
        else  ditu[a][b].tot=1; // 点到炸弹周围，记录一下
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ditu[i][j].tot==-1)cout<<ditu[i][j].tot<<" ";
                else cout<<ditu[i][j].num<<" ";//搜索过的输出炸弹数，未搜索过的就按照题意输出-1 
                if(ditu[i][j].tot==-1&&ditu[i][j].num!=-1)flag=0;//有未搜索到的且不是地雷的就代表未胜利
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
