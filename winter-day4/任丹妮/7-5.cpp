#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
};
struct Node{
    int x,y,cost;
    vector<node>path;
};
int Map[100][100];
int visit[100][100]={0};
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int start_x,start_y,end_x,end_y;
    Node start,End;
void bfs(){
    queue<Node>q;
    Node minNode;
    int i,min=2333333;
    q.push(start);
    while(!q.empty()){
        Node temp=q.front(),newpos;
        q.pop();
        if(temp.x==end_x&&temp.y==end_y){
            if(min>temp.cost) min=temp.cost;
            minNode=temp;
            continue;
        }
        for(int i=0;i<4;i++){
            newpos.x=temp.x+d[i][0];
            newpos.y=temp.y+d[i][1];
            if(Map[newpos.x][newpos.y]!=-1){
                newpos.cost=Map[newpos.x][newpos.y]+temp.cost;
                if(visit[newpos.x][newpos.y])
                    if(visit[newpos.x][newpos.y]>newpos.cost) visit[newpos.x][newpos.y]=newpos.cost;
                    else continue;
                 else visit[newpos.x][newpos.y]=newpos.cost;
                 newpos.path=temp.path;
                 newpos.path.push_back({temp.x,temp.y});
                 q.push(newpos);
        }
    }
    }
    cout<<"("<<End.x<<" "<<End.y<<")";
    while(!minNode.path.empty()){
        cout<<"("<<minNode.path.back().x<<" "<<minNode.path.back().y<<")";
        minNode.path.pop_back();
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    cin>>start_x>>start_y>>end_x>>end_y;
    start.x=start_x;
    start.y=start_y;
    start.cost=0;
    End.x=end_x;
    End.y=end_y;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>Map[i][j];
    bfs();
    return 0;
}
