/*
7-4 岛屿数量
给你一个由 1（陆地）和 0（水）组成的n*m的二维网格，请你计算网格中岛屿的数量num。
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。例如
例	例	例
0	0	0
0	1	0
0	0	1
此为两个岛屿
此外，你可以假设该网格的四条边均被水包围。1<=n,m<=100
输入格式:
第一行中给出网格长宽n,m 接下来的n行表示网格情况
输出格式:
岛屿个数num
输入样例:
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
输出样例:
3
*/
#include <bits/stdc++.h>
using namespace std;
int a[128][128];
int n,m,count;
int find(int x,int y){
    if(x>n || y>m || x<1 || y<1|| !a[x][y]) return 0;
    a[x][y]=0;
    find(x+1,y);
    find(x,y+1);
    find(x-1,y);
    find(x,y-1);
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(find(i,j)>0) count++;
    cout<<count;
}
