#include<bits/stdc++.h>
using namespace std;
int n;
int hou[11],in[11];
typedef struct node{
    int data;
    node *left,*right;
}node,*linknode;
void crea(linknode &root,int *hou,int *in,int hl,int hr,int il,int ir){
    if(hl<=hr){
        root=new node;
        root->data=hou[hr];
        root->left=NULL;
        root->right=NULL;

        int j;
        for(j=il;j<=ir;j++){
            if(in[j]==hou[hr])
            break;
        }
        crea(root->left,hou,in,hl,hl+j-il-1,il,j-1);
        crea(root->right,hou,in,hl+j-il,hr-1,j+1,ir);
    }
}
void pre(linknode &root){
    if(root!=NULL){
        cout<<root->data<<" ";
        pre(root->left);
        pre(root->right);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    scanf("%d",&hou[i]);
    for(int i=0;i<n;i++)
    scanf("%d",&in[i]);
    linknode root;
    crea(root,hou,in,0,n-1,0,n-1);
    pre(root);
    return 0;
}