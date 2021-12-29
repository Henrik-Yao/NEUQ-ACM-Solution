/*
7-1 图的创建
请编写程序创建一个有向图。有向图中包含n个顶点，编号为0至n-1。
输入格式:
输入第一行为两个正整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过20000。
接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值。
各边并非按端点编号顺序排列。
输出格式:
按顶点编号递增顺序输出每个顶点引出的边，每个顶点占一行，若某顶点没有引出边，则不输出。
每行表示一个顶点引出的所有边，格式为a:(a,b,w)……，表示有向边a->b的权值为w，
a引出的多条边按编号b的递增序排列。
输入样例:
7 7
0 1 5
0 3 7
0 6 6
1 2 4
2 5 1
3 5 3
6 5 4
输出样例:
0:(0,1,5)(0,3,7)(0,6,6)
1:(1,2,4)
2:(2,5,1)
3:(3,5,3)
6:(6,5,4)
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	int from,to,weight;
};
bool cmp(node a, node b){
	if(a.from!=b.from) return a.from<b.from;
	else return a.to<b.to;
}
node a[20005];
int count[20005];
int main(){
    ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>a[i].from>>a[i].to>>a[i].weight;
		count[a[i].from]++;
	}
	sort(a,a+m,cmp);
	for(int i=0;i<n;++i){
		if(!count[i]) continue;
		int sum=count[i];
		cout<<a[i].from;
		for(int j=0;j<sum;j++) cout<<"("<<a[j].from<<","<<a[j].to<<","<<a[j].weight<<")";
		cout<<endl;
	}
}
