#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int u;
	int v;
	int w;
}Edge;
int a[201];
bool cmp(Edge edge1,Edge edge2){
	return edge1.w<edge2.w;
}

void init(){
	for(int i=0;i<201;i++){
		a[i]=i;
	}
}

int find(int x){
	int r=x;
	while(a[r]!=r)
	r=a[r];
	return r;
}


int join(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		a[fy]=fx;
		return 1;
	}
	return 0;
}

int main(){
	int n,e;
	while(cin>>n>>e){
		Edge edge[e];
		init();
		for(int i=0;i<e;i++){
			cin>>edge[i].u>>edge[i].v>>edge[i].w;
		}
		sort(edge,edge+e,cmp);
		int cnt=0,w_sum=0;
		for(int i=0;i<e;i++){
			if(join(edge[i].u,edge[i].v)){
				cnt++;
				w_sum+=edge[i].w;
			}
			if(cnt==n-1)
			break;
		}
		if(cnt==n-1)
		cout<<w_sum<<endl;
		else cout<<"There is no minimum spanning tree."<<endl;
	} 
	return 0;
}
