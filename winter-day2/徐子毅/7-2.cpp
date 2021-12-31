#include <iostream>
#include <cstring>
using namespace std;
struct tree{
	char data;
	tree * lchild;
	tree * rchild;
};
string post;
string in;
bool judge(string a,string b){
	if(a.size()==0 && b.size()==0) return true;
	if(a.size()!=b.size()) return false;
	char ch;
	ch = a[a.size()-1];
	int i=0;
	for(i=0;i<b.size();i++) if(b[i]==ch) break;
	string al=a.substr(0,i),ar=a.substr(i,a.size()-1-i);
	string bl=b.substr(0,i),br=b.substr(i+1,a.size());
	for(int i=0;i<al.size();i++){
		if(bl.find(al[i])==-1) return false;
	}
	for(int i=0;i<ar.size();i++){
		if(br.find(ar[i])==-1) return false;
	}
	return judge(al,bl) && judge(ar,br);
}
tree * createfront(int postfront,int postend,int infront,int inend){
	if(postfront>postend||infront>inend) return NULL;
	if(postfront==postend&&infront==inend){
		tree * leave=new tree;
		leave->data=post[postend];
		leave->lchild=NULL;
		leave->rchild=NULL;
		return leave;
	}
	char chroot=post[postend];
	int i;
	for(i=postfront;i<=postend;i++) if(in[i]==chroot) break;
	tree * BT=new tree;
	BT->data=chroot;
	BT->lchild=createfront(postfront,postfront+i-infront-1,infront,i-1);
	BT->rchild=createfront(postend+i-inend,postend-1,i+1,inend);
	return BT;
}
int gethigh(tree *BT){
	if(!BT){
		return 0;
	}
	int left=gethigh(BT->lchild);
	int right=gethigh(BT->rchild);
	return max(left,right)+1;
}
void pre(tree *BT){
	if(!BT) return;
	cout << BT->data;
	pre(BT->lchild);
	pre(BT->rchild);
}
int main(){
	int n;
	while(cin>>post>>in){
		if(judge(post,in)==false){
			cout << "INVALID" << endl;
			continue;
		}else{
			tree * root =new tree;
			root=createfront(0,post.size()-1,0,in.size()-1);
			cout << gethigh(root)-1 << endl;
			pre(root);
			cout << endl;
		}
	}
}