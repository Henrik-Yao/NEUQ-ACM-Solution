#include<bits/stdc++.h>
using namespace std;
typedef struct tree* ltree;
typedef struct tree* rtree;
struct tree{
int data;
int level;
ltree left;
rtree right;
};
int sum[105];
int num[105];
int maxlevel=0;
ltree createtree(int level){
	int n;
	cin>>n;
	if(n==0) return NULL;
	ltree bt=(ltree)malloc(sizeof(tree));
	bt->data=n;
	bt->level=level;
	if(bt->level>maxlevel){
		maxlevel=bt->level;
	}
	bt->left = createtree(level+1);
	bt->right = createtree(level+1);
	return bt;
}
void it(ltree bt){
	if(bt==NULL) return;
	if(bt->left==NULL&&bt->right==NULL){
		sum[bt->level]+=bt->data;
		num[bt->level]++;
	}
	it(bt->left);
	it(bt->right);
}
int main(){
	ltree bt=createtree(0);
	it(bt);
	int maxnum=-1000;
	int level=-1;
	for(int i=0;i<=maxlevel;i++){
		if(sum[i]>=maxnum&&num[i]!=0){
			maxnum=sum[i];
			level=i;
		}
	}
	cout<<level;
}
