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
int merge(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
	f[a]=f[b];
	return 1;
 }
 return 0;
}
int n,m,e;
int main(){
	while(cin>>n>>e>>m){
	for(int i=0;i<n;i++)f[i]=i;
	for(int i=0;i<m;i++){
		cin>>node[i].x>>node[i].y>>node[i].w;
	}
	sort(node,node+m,cmp);
	int cnt=0;
	int sum=0;
	int num=0;
	for(int i=0;i<m;i++){
		  if((node[i].x==e||node[i].y==e)&&cnt<2){
		 if(merge(node[i].x,node[i].y)){
		 	num++;
		 	cnt++;
		 	sum+=node[i].w;
		 }
	 }
	 else if(node[i].x!=e&&node[i].y!=e){
	 	if(merge(node[i].x,node[i].y)){
		 	num++;
		 	sum+=node[i].w;
		 }
	 }
	 if(num==n-1)break;
	}
	if(cnt<=2&&num==n-1)cout<<sum<<endl;
	else cout<<"-1"<<endl;
}
	return 0;
}
