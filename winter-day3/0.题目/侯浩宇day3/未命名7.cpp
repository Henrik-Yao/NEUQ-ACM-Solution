#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int u;//顶点1
	int v;//顶点2 
	int w;//权值 
}Edge;//结构体存边的信息 
int a[201];
int pp;
bool cmp(Edge edge1,Edge edge2){
	return edge1.w<edge2.w;
}

void init(){//初始化 
	for(int i=0; i<201; i++){
		a[i] = i;
	}
}

int find(int x){//查找 
	int r = x;
	while(a[r]!=r)
		r = a[r];
	return r;
}

int join(int x,int y){//合并 
	int fx = find(x);
	int fy = find(y);
	if(fx!=fy&&pp){
		pp--;
		a[fy] = fx;
		return 1;
	}
	return 0;
}

int main(){
    int n,e,v;
    while(cin >> n>>v >> e){
    	Edge edge[e];pp=2;
    	init();
    	for(int i=0; i<e; i++){
    		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		}
		sort(edge,edge+e,cmp); //边按权值从小到大排序 
		int cnt=0, w_sum=0; //边数、权值和
		for(int i=0; i<e; i++){
			if(edge[i].u==v||edge[i].v==v){
				int fx = find(edge[i].u);
				int fy = find(edge[i].v);
				if(fx!=fy&&pp){
					pp--;
					a[fy] = fx;
					cnt++;
					w_sum += edge[i].w;						
				}

				}
				else if(edge[i].u!=v&&edge[i].v!=v){
					int fx = find(edge[i].u);
					int fy = find(edge[i].v);
					if(fx!=fy){				
					cnt++;
					w_sum += edge[i].w;
					a[fy]=fx;					
				}
				
			}
			if(cnt==n-1) //边数 = 顶点数-1，找到最小生成树 
				break;
		}
		if(cnt==n-1)
			cout << w_sum << endl;
		else cout << -1 << endl; 
	}
    return 0;
}
