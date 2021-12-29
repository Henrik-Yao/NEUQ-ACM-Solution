#include<bits/stdc++.h>
using namespace std;
const int k = 1e4;
int fa[210];
bool vis[k];
struct Node{
	int x,y,val;
};

bool cmp(Node node1,Node node2){
	return node1.val < node2.val;
}

int find(int x){
	if(fa[x] == x)
		return x;
	else return fa[x] = find(fa[x]);
}

void join(int x,int y){	
	int a = find(x);
	int b = find(y);
	if(a!=b)
		fa[a] = b;
}

int main(){
	int n,e;
	while(cin >> n >> e){
		struct Node node[e+10];
		memset(vis,0,sizeof(vis));
		int a,b,c;
		for(int i = 1;i <= n;i++){
			fa[i] = i;
		}
		for(int i = 0;i < e;i++){
			cin >> a >> b >> c;
			node[i].x = a;
			node[i].y = b;
			node[i].val = c;
			join(a,b);	
		}
		int num = 0;
		for(int i = 1;i <= n;i++){
			if(fa[i] == i)
				num++;
		}
		if(num==1){
			sort(node,node+e,cmp);
		int cnt = 0;
		for(int i = 0;i < e;i++){
			if(vis[node[i].x] == 1 && vis[node[i].y] == 1){	
				continue;
			}
            else{
				vis[node[i].x] = 1;
				vis[node[i].y] = 1;
				cnt += node[i].val;
			}
		}
		cout << cnt << endl;
		}
		else{
			cout << "There is no minimum spanning tree." << endl;
		}
	}
} 

