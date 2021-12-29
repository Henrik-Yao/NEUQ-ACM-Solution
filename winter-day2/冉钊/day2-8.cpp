#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int flag=0,cou;
typedef struct node{
    int data;
    struct node *left,*right;
    node(){
        left=right=NULL;
    }
}node,*linknode;
int t,n;
void crea(linknode &root,int *a,int len,int i){
    if(i<=len){
        if(a[i]!=0){
        root=new node;
        root->data=a[i];}
        else{ root=NULL;return;}

        if(i*2<=len&&a[i*2]!=0)
        crea(root->left,a,len,i*2);
        if((i*2+1)<=len&&a[i*2+1]!=0)
        crea(root->right,a,len,i*2+1);
    }
}

void in(linknode &root){
    if(root){
        in(root->left);
        cout<<root->data;
        flag++;
        if(flag!=cou)cout<<" ";//判断是否是最后一次输出；
        in(root->right);
    }
}
int getdeep(linknode &t)
{
	int l,r;
	if(t==NULL)
		return 0;
	else{
		l=getdeep(t->left);
		r=getdeep(t->right);
		if(l>r)
		return l+1;
		else return r+1;
	}
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        cou=n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0)cou--;
        }
        linknode root;
        crea(root,a,n,1);
        in(root);
        cout<<endl;
        cout<<getdeep(root)<<endl;
        flag=0;
    }
    return 0;
}