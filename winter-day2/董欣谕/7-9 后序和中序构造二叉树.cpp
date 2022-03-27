#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct Tree{
	int value;
	Tree *L=NULL;
	Tree *R=NULL;
};
int a1[1001],a2[1001];
int istree;
void preorder(Tree *t){
	if (t==NULL) return;
	cout<<t->value<<" ";
	preorder(t->L);
	preorder(t->R);
}
// l1 a1 ,l2 a2
void createtree(Tree *&t,int len,int l1,int l2){
	int r1=l1+len-1;
	int r2=l2+len-1;
	int pos;
	for (pos=l2;pos<=r2;pos++)
		if (a2[pos]==a1[r1]) break;
	int leftlen=pos-l2;
	int rightlen=r2-pos;
	t=new Tree;
	t->value=a1[r1];
	if (leftlen>0) createtree(t->L,leftlen,l1,l2);
	if (rightlen>0) createtree(t->R,rightlen,pos-l2+l1,pos+1);
}
// a1 : l1,r1
// a2 : l2,r2
// a2 l2,pos-1  a1 l1,pos-1-l2+l1 
// a2 pos+1,r2  a1 pos-l2+l1,r1-1
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a1[i];
	for (int i=0;i<n;i++)
		cin>>a2[i];
	Tree *root;
	root =new Tree;
	createtree(root,n,0,0);
	preorder(root);
	return 0;
} 
