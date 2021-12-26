#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
typedef struct node{
	int v;
	struct node *l,*r;
}node,*tree;
int dep[1001];
void create(tree *T){
	int x;
	cin>>x;
    if (x==0) *T=NULL;
	else {
		*T=new node;
		(*T)->v=x;
		create(&(*T)->l);
		create(&(*T)->r);
	}
}
int bfs(node *root){
	if (root==NULL) return 0;
	queue<pair<node*,int> >q;
	int depth=0;
	q.push(make_pair(root,depth));
	while (!q.empty()){
		node *front=q.front().first;
		q.pop();
		dep[q.front().second]+=front->v;
		depth=max(q.front().second,depth);
		if (front->l!=NULL) q.push(make_pair(front->l,depth+1));
		if (front->r!=NULL) q.push(make_pair(front->r,depth+1));
	}
	return depth;
}


int depth=1;
void P(tree BT){
	if(BT){
		if(BT->l==NULL&&BT->r==NULL) dep[depth]+=BT->v;			 
		P(BT->l); 
		P(BT->r); 
		if(BT->l!=NULL&&BT->r!=NULL) depth++;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    tree T;
	create(&T);
    P(T);
	int ans=0,maxsum=dep[0];
    for (int i=1;i<depth;i++){
    	//cout<<dep[i]<<" ";
    	if (maxsum<=dep[i]) {
    		ans=i;
    		maxsum=dep[i];
		}
	}
	cout<<ans;
	return 0;
} 