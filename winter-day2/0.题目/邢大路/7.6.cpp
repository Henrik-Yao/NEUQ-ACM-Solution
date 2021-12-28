#include<bits/stdc++.h>
using namespace std;
const int N=1100;
int pre[N];
int in[N];
int a[N];
int l[N];
int r[N];
struct Node{
	int l;
	int r;
}node[N];
int build(int l1,int r1,int l2,int r2){
	if(l1>r1)return 0;
	int root=pre[l2];
	int p=l1;
	while(in[p]!=root)p++;
	int cnt=p-l1;
	
	node[root].l=build(l1,p-1,l2+1,l2+cnt);
	node[root].r=build(p+1,r1,l2+cnt+1,r2);
	return root;
}
void bfs(int root){
	if(root==0)return;
	bfs(node[root].l);
	bfs(node[root].r);
		cout<<root<<" ";
	
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pre[i];
	}
	for(int i=1;i<=n;i++){
		cin>>in[i];
	}
    memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	int root=build(1,n,1,n);
	bfs(root);
	
	return 0;
}
