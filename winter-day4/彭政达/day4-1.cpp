/*
7-1 双十一
双十一期间，某著名电商平台“东东”为应对销售高峰，准备在n个城市中再增加一个自营仓库，
其要求是该仓库设在n个城市中的某个城市，且距离其他所有城市的最短距离之和最小。
请编写程序帮助“东东”找出设立仓库的地点。假定n个城市编号为0至n-1，
它们之间至少有一个城市与其他所有城市可及。
输入格式:
输入包含多组数据。每组数据第一行为两个正整数n和e，均不超过100。n表示城市数。
接下来e行表示两个城市间的距离信息，每行为3个非负整数a、b、c，
其中a和b表示两个城市编号，c表示城市间的距离。
提示：可使用EOF判断输入结束。
输出格式:
输出为一个整数，表示建立仓库的城市编号，如多个城市满足要求，则输出编号最小者。
输入样例:
6 5
0 1 1
0 2 1
0 3 1
0 4 1
0 5 1
4 5 
0 1 1        0-1 1 -2 5 -3 5             
0 2 5  1-0 1       -2 2 -3 4             
1 2 2  2-0 5  -1 2      -3 1             
1 3 4  3-0 5  -1 4 -2 1                 
2 3 1                          
输出样例:
0
1
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("in1.txt","r",stdin);
    int lo,vertex,edge,g[128][128];
    while(cin>>vertex>>edge){
    	if(vertex==EOF) break;
        memset(g,128,sizeof(g));
        for(int i=1;i<=edge;i++){
            int from,to,weight;
            cin>>from>>to>>weight;
            if(++from==++to) g[from][to]=0;
            else{
                g[from][to]=weight;
                g[to][from]=weight;
            }
        }
        for(int i=1;i<=vertex;i++)
            for(int j=1;j<=vertex;j++)
                for(int k=1;k<=vertex;k++)
                    if(g[j][k]>g[j][i]+g[i][k]) g[j][k]=g[j][i]+g[i][k];
        long long dis[128]={0},ans=2147483647;
        for(int i=1;i<=vertex;i++)
            for(int j=1;j<=vertex;j++)
                if(i!=j) dis[i]+=(long long)g[i][j];
        lo=1;
        for(int i=1;i<=vertex;i++)
            if(dis[i]<ans) ans=dis[i],lo=i;
        cout<<lo-1<<endl;
    }
}
