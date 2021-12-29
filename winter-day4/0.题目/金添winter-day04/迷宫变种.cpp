#include <bits/stdc++.h>
using namespace std;
int l,w;                //l长，w宽
int start_x, start_y, end_x, end_y; //起点，终点
int map1[100][100]; //记录图
int dis[100][100];  //记录起点到任意一点的距离(能量耗值)
int ans[100][2];      //存最终答案的数组坐标
int path[100][2];     //存到所有点的通用路径(暂时容器)
int dirx[4]={0,0,-1,1};
int diry[4]={1,-1,0,0}; //位移变量
int cnt=0;              //记录各条路的路线经过点数
int sum=0;              //记录最终答案的经过点数
void search(int x,int y)
{
    if(x==end_x&&y==end_y)
    {
        for(int i=0;i<cnt;i++)
        {
            ans[i][0]=path[i][0];
            ans[i][1]=path[i][1];//路径配置成功！将路径拷贝入最终路径中
        }
        sum=cnt;    //路径数赋值
        return;
    }
    for(int i=0;i<4;i++)
    {
        int dx=x+dirx[i];
        int dy=y+diry[i];
        if(map1[dx][dy]!=-1&&(dx<l&&dx>=0)&&(dy<=w&&dy>=0)&&dis[x][y]+map1[dx][dy]<dis[dx][dy])
        {
            //若满足，说明是可以选择的中介点
            dis[dx][dy]=dis[x][y]+map1[dx][dy];
            path[cnt][0]=dx;
            path[cnt][1]=dy;
            cnt++;
            search(dx,dy);
            cnt--; //关键中的关键！一定要回溯！如果这条路不能到终点，直接一层一层回溯，抛出，重置。
        }
    }
}
int main()
{
    memset(dis,0x3f,sizeof(dis));
    cin >> l >> w;
    cin >> start_x >> start_y >> end_x >> end_y;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> map1[i][j];
        }
    }
    int s=start_x,e=start_y;
    dis[s][e]=map1[s][e];  //将起点先赋入
    path[cnt][0]=s;
    path[cnt][1]=e;      //将起点塞入路径中
    cnt++;
    search(s,e);
    for(int i=sum-1;i>=0;i--)
    cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<")";
    return 0;
}
/*
10 10
3 6 8 8
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1  2  1  1  1  1  1  5  1 -1
-1  1  9  9  9  1  1 -1  1 -1
-1  1  1  1  1  1  1 -1  1 -1
-1  1 -1 -1 -1 -1 -1 -1  1 -1
-1  1  9  9  9  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  2 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
/*
 --------------------------->x
|从0开始
|
|
|
|
|
|
|
^y
*/
/*


*/