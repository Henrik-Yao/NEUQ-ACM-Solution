#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int f[N];
struct Node{
	int x;
	int y;
	int w;
}node[N];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int find(int x){
	if(x==f[x])return x;
	else return f[x]=find(f[x]);
}
void merge(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b)
	f[a]=f[b];
}
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>node[i].x>>node[i].y>>node[i].w;
	}
	sort(node+1,node+m+1,cmp);
	int count=0;
	int h=0;
	for(int i=1;i<=m;i++){
		  if(find(node[i].x)!=find(node[i].y)){
		    count++;
     		if(node[i].w>h)h=node[i].w;
	    	merge(node[i].x,node[i].y);
			if(count==n-1)break;
	 }
	}
	cout<<n-1<<" "<<h;
	return 0;
}
