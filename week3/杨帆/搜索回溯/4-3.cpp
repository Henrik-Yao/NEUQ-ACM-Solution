#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,site[50][50],boom[50][50],book[50][50];
bool check(){
    int sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(site[i][j]==-1)
                sum++;
        }
    if(sum==k)  return true;
    return false;
}

void bfs(int x,int y){
    queue<pair<int,int> >que;
    que.push({x,y});
    book[x][y]=1;
    int kx[8]={1,1,1,0,0,-1,-1,-1};
    int ky[8]={-1,0,1,-1,1,-1,0,1};
    while(!que.empty()){
        int dx=que.front().first;
        int dy=que.front().second;
        que.pop();
        int num=0;
        for(int i=0;i<8;i++){
            int dxx=dx+kx[i];
            int dyy=dy+ky[i];
            if(dxx>=0&&dyy>=0&&dxx<n&&dyy<m){
                if(boom[dxx][dyy]==1)  num++;
            }
        }
            if(num!=0)    site[dx][dy]=num;
            else{
                site[dx][dy]=0;
                for(int i=0;i<8;i++){
                    int dxx=dx+kx[i];
                    int dyy=dy+ky[i];
                    if(dxx>=0&&dyy>=0&&dxx<n&&dyy<m&&book[dxx][dyy]==0){
                        book[dxx][dyy]=1;
                        site[dxx][dyy]=0;
                        que.push({dxx,dyy});
                    }
                }
            }
    }
}

int main(){
    cin>>n>>m>>k>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            site[i][j]=-1;
    }
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        boom[a][b]=1;
    }
    while(l--){
        int a,b;
        cin>>a>>b;
        if(boom[a][b]==1){
        		cout<<"You lose";
        		return 0;
				}
        else if(book[a][b]==1) continue;
        else{
            bfs(a,b);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<site[i][j]<<" ";
                }
                cout<<"\n";
            }
            if(check()){
                cout<<"You win";
                return 0;
            }
            else    cout<<"\n";
        }
    }
    return 0;
}
