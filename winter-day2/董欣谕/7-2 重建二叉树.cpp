#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct Tree{
	char ch;
	Tree *L=NULL;
	Tree *R=NULL;
};
string post,in;
int istree;
int depth(Tree *t){
	if (t==NULL) return -1;
	int dep1=depth(t->L)+1;
	int dep2=depth(t->R)+1;
	return max(dep1,dep2);
}
void preorder(Tree *t){
	if (t==NULL) return;
	cout<<t->ch;
	preorder(t->L);
	preorder(t->R);
}
// l1 post ,l2 in
void createtree(Tree *&t,int len,int l1,int l2){
	int flag=0;
	int r1=l1+len-1;
	int r2=l2+len-1;
	int pos=in.find(post[r1]);
	if (pos>=l2&&pos<=r2) {
		flag=1;
	}
	int leftlen=pos-l2;
	int rightlen=r2-pos;
	if (flag){
		t=new Tree;
		t->ch=post[r1];
		if (leftlen>0) createtree(t->L,leftlen,l1,l2);
		if (rightlen>0) createtree(t->R,rightlen,pos-l2+l1,pos+1);
	}
	else {
		istree=0;
	}
}
// post : l1,r1
// in : l2,r2
// in l2,pos-1  post l1,pos-1-l2+l1 
// in pos+1,r2  post pos-l2+l1,r1-1
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	while (cin>>post>>in){
		istree=1;
		Tree *root;
		root =new Tree;
		int len=in.length();
		createtree(root,len,0,0);
		if (istree==0) cout<<"INVALID"<<endl;
		else {
			cout<<depth(root)<<endl;
			preorder(root);
			cout<<endl;
		}
	}
	return 0;
} 
