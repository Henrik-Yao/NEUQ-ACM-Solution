#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct Tree{
	int value;
	Tree* l;
	Tree* r;
};
int n;
int a1[100],a2[100];
void bfs(Tree *root){
	queue<Tree*>q;
	q.push(root);
	while (!q.empty()){
		Tree* now=q.front();
		q.pop();
		cout<<now->value<<" ";
		if (now->l!=NULL) q.push(now->l);
		if (now->r!=NULL) q.push(now->r);
	}
	return;
}
void postorder(Tree *t){
	if (t==NULL) return;
	postorder(t->l);
	postorder(t->r);
	cout<<t->value<<" ";
}
void create(Tree *&t,int len,int l1,int l2){
	if (len<=0) {
		t=NULL;
		return;
	}
	int r1=l1+len-1;
	int r2=l2+len-1;
	int pos;
	for (pos=l2;pos<=r2;pos++)
		if (a2[pos]==a1[l1]) break;
	int leftlen=pos-l2;
	int rightlen=r2-pos;
	t=new Tree;
	t->value=a1[l1];
	create(t->l,leftlen,l1+1,l2);
	create(t->r,rightlen,r1-(r2-pos-1),pos+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a1[i];
	for (int i=1;i<=n;i++)
		cin>>a2[i];
	Tree *root;
	create(root,n,1,1);
	//postorder(root);
	bfs(root);
	return 0;
} 
