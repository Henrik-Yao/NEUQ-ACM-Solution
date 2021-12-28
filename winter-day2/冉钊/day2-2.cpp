#include<bits/stdc++.h>
using namespace std;
int n,cs=1;
string hx,zx,s1,s2;
map<char,int>ph,pz;
typedef struct node{
    char data;
    struct node *left,*right;
    node(){
        left=right=NULL;
    }
}node,*linknode;
int find(int z,int y){
	if(z==y)return zx[z];
	if(z>y)return '#';
	int cnt=-1;
	char max;
	for(int j=z;j<=y;j++){
		if(ph[zx[j]]>cnt)cnt=ph[zx[j]],max=zx[j];
	}
	return max;
}
linknode crea(int z,int y){
	char a=find(z,y);
	linknode root;
	if(a=='#'){
		root=NULL;
	}
	else {
		root =new node;
		root->data =a;
		root->left=crea(z,pz[a]-1);
		root->right=crea(pz[a]+1,y);
	}
	return root;
}
void hou(linknode &root){
    if(root){
        hou(root->left);
        hou(root->right);
        s1+=root->data;
    }
}
void in(linknode &root){
    if(root){
        in(root->left);
        s2+=root->data;
        in(root->right);
    }
}
void pre(linknode &root){
    if(root){
    	cout<<root->data;
        pre(root->left);
        pre(root->right);
    }
}
int getdeep(linknode &root){
    int l,r;
    if(root){
         l=getdeep(root->left);
         r=getdeep(root->right);
        if(l>r) return l+1;
        else return r+1;
    }
    else return 0;
}
int main(){

    while(cin>>hx>>zx){
        n=hx.size();
		for(int i=0;i<n;i++)ph[hx[i]]=i,pz[zx[i]]=i;
		linknode tt=NULL;
		tt=crea(0,n-1);
		in(tt),hou(tt);
		if(hx!=s1||zx!=s2){
			for(int i=0;i<n;i++)s1.erase(0),s2.erase(0);
			cout<<"INVALID"<<endl;
			continue;
		}
		for(int i=0;i<n;i++)s1.erase(0),s2.erase(0);
		cout<<getdeep(tt)-1<<endl;//这里对层的定义不太一样，根不算层，s要减一；
		pre(tt);
		cout<<endl;
		
		cs=1;
    }


    return 0;
}