/*
7-6 最小支撑树
给定一个包含n个顶点的正权无向图，编号为1至n。请编写程序求出其最小支撑树，并计算其边权之和。
输入格式:
输入包含多组数据。每组数据第一行为2个整数n和e，均不超过1500，分别表示图的顶点数和边数。
接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，
c表示权值，不超过100。各边并非按端点编号顺序排列。
输出格式:
对于每组数据，若存在最小支撑树则输出一个整数，为最小支撑树各边权值之和；
若不存在最小支撑树，则输出“There is no minimum spanning tree.”。
输入样例:
4 5
1 2 1
1 4 1
2 4 5
2 3 1
3 4 8
4 2
1 2 1
3 4 8
输出样例:
3
There is no minimum spanning tree.
*/
#include<bits/stdc++.h>
using namespace std;
int f[1555];
typedef struct node{
	int from,to,weight;
};
bool cmp(tree a,tree b){
	return a.weight<b.weight;
}
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void merge(int x,int y){
	int a=find(x),b=find(y);
	if(a!=b) f[a]=b;
}
int main(){
	int vertex,edge;
	ios::sync_with_stdio(false);
	freopen("in6.txt","r",stdin);
	while(cin>>vertex>>edge){
		node n[edge+1];
		int flag[1555]={0};
		int a,b,c;
		for(int i=0;i<vertex;i++) f[i]=i;
		for(int i=0;i<edge;i++){
			cin>>a>>b>>c;
			n[i].from=a;
			n[i].to=b;
			n[i].weight=c;
			merge(a,b);
			int x=find(a),y=find(b);
			if(a!=b) f[a]=b;
		}
		int num=0;
		for(int i=0;i<vertex;i++)
			if(f[i]==i) num++;
		if(num==1){
			sort(n,n+edge,cmp);
			int sum=0;
			for(int i=0;i<edge;i++)
				if(flag[n[i].from] && flag[n[i].to]) continue;
				else{
					flag[n[i].from]=flag[n[i].to]=1;
					sum+=n[i].weight;
				}
			cout<<sum<<endl;
		}
		else cout<<"There is no minimum spanning tree."<<endl;
	}
} 
