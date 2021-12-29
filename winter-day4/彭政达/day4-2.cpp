/*
7-2 路由器
快速的信息传送已经成为必须。信息传送工作由位于网络节点上的路由器来实现。
每个路由器都维护一个“路由器表”，给出它可以直接到达的路由器编号。
很明显，信息传送要求经过的路由器最少（也被称为“跳数”）。
对于给出的网络，要求编写程序发现从信息源到目标节点的最佳路线（最少跳数）。
假定n个路由器编号为0至n-1，网络中路由器数目不超过200，且至少有2个路由器，
每个路由器最多和50个路由器直接相连。
输入格式:
输入包含多组测试数据。每组数据输入第一行为整数n和m，表示网络中路由器数。
接下来n行表示每个路由器可直接到达的路由器ID列表，每行为一组空格间隔的整数，
格式为i k v1 v2 ... vk，其中i表示路由器编号，k为路由器i可直接到达的路由器数，
接下来k个数 v1 v2 ... vk?表示路由器i可直接到达的路由器编号。
接下来m行，表示m组查询，每行两个整数a和b，表示起始路由器和终点路由器编号。
提示：可使用EOF判断输入结束
输出格式:
对每组测试数据，输出m行，每行为信息从路由器a传送到路由器b所需经过的最小跳数，
如果不可能进行信息传送（起始路由器和终点路由器不连通），则输出“connection impossible”。
输入样例:
6 2
0 5 1 2 3 4 5
1 0
2 0
3 0
4 0
5 0
0 2
1 2
4 2
0 2 1 2
1 2 2 3
2 1 3 
3 1 2
0 3
1 0
输出样例:
1
connection impossible
2
connection impossible
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 10000
int g[128][128];
int n,m,a,b,c,count;
int main(){
	freopen("in2,txt","r",stdin);
    while(cin>>n>>m){
    	if(n==EOF) break;
    	memset(g,INF,sizeof(g));
    	int a,b,c;
    	for(int i=0;i<n;i++){
        	cin>>a>>c;
        	for(int j=0;j<c;j++){
            	cin>>b;
            	if(a==b) g[a][b]=0;
            	else g[a][b]=1;
        	}
    	}
    	for(int i=0;i<n;i++)
    	    for(int j=0;j<n;j++)
    	        for(int k=0;k<n;k++)
    	            if(g[j][k]>g[j][i]+g[i][k]) g[j][k]=g[j][i]+g[i][k];
    	int from,to;
    	for(int i=0;i<m;i++){
        	cin>>from>>to;
    		ans=g[from][to];
    		if(count>=INF) cout<<"connection impossible"<<endl;
    		else cout<<count<<endl;
    	}
    }
}
