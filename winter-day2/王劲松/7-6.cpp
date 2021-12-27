#include<bits/stdc++.h>
using namespace std;
int n,i,xx[10],zx[10];
map<int,int>px,pz;
int find(int z,int y);
typedef struct tree{
	int data;
	struct tree *l,*r;
}tree,*linktree;
linktree createtree(int z,int y){
	int a=find(z,y);
	linktree node;
	if(a==-1){
		node=NULL;
	}
	else {
		node =(linktree)malloc(sizeof(tree));
		node->data =a;
		node->l=createtree(z,pz[a]-1);
		node->r=createtree(pz[a]+1,y);
	}
	return node;
}
void pr(linktree tt){
	if(tt->l!=NULL)pr(tt->l);
	if(tt->r!=NULL)pr(tt->r);
	cout<<tt->data <<" ";
}
int main(){
	cin>>n;
	for(i=0;i<n;i++)cin>>xx[i],px[xx[i]]=i; 
	for(i=0;i<n;i++)cin>>zx[i],pz[zx[i]]=i; 
	linktree tt=NULL;
	tt=createtree(0,n-1);
	pr(tt);
	return 0;
}
int find(int z,int y){
	if(z==y)return zx[z];
	if(z>y)return -1;
	int cnt=n,min;
	for(int j=z;j<=y;j++){
		if(px[zx[j]]<cnt)cnt=px[zx[j]],min=zx[j];
	}
	return min;
}
