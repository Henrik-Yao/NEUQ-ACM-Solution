#include<bits/stdc++.h>
using namespace std;
int qh[100],j=1,vi[100];
typedef struct tree{
	int data;
	struct tree *l,*r;
}tree,*linktree;
linktree createtree(){
	int a;
	linktree node;
	cin>>a;
	if(!a)node=NULL;
	else {
		node=(linktree)malloc(sizeof(tree));
		node->data=a;
		node->l =createtree(),node->r =createtree();
	}
	return node;
}
void sum(linktree tr,int j);
int main(){
	linktree t0=NULL;
	t0=createtree();
	sum(t0,j);
	int cs,maxcs=-100000;
	for(int k=1;k<100;k++){
		if(!vi[k])continue;
		if(qh[k]>maxcs)maxcs=qh[k],cs=k;
		if(qh[k]==maxcs)cs=k;
	}

	cout<<cs-1<<endl;
	return 0;
}
void sum(linktree tr,int j){
	if(tr->l ==NULL&&tr->r ==NULL)qh[j]+=tr->data ,vi[j]=1;//cout<<"qh["<<j<<"]="<<qh[j]<<endl;;
	if(tr->l )sum(tr->l ,j+1);
	if(tr->r )sum(tr->r ,j+1);
	
	return ;
}
