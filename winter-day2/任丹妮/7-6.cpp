#include <bits/stdc++.h>
using namespace std;
#define N 15
typedef struct BTNode{
    int data;
    BTNode *lchild,*rchild;
}BTNode,*BiTree;
void postTraverse(BiTree T){
    if(T){
        postTraverse(T->lchild);
        postTraverse(T->rchild);
        cout<<T->data<<" ";
    }
}
BiTree CreatBiTree(int *pre,int *in,int n){
    int i=0;
    BiTree T;
    int prel[N],prer[N];
    int inl[N],inr[N];
    if(n==0){
        return NULL;
    }
    T=(BiTree)malloc(sizeof(BTNode));
    //memeset(T,0,sizeof(BTNode));
    int n1=0,n2=0;
    int m1=0,m2=0;
    T->data=pre[0];
    for(i=0;i<n;i++){
        if(i<=n1&&in[i]!=pre[0]){
            inl[n1++]=in[i];
        }
        else if(in[i]!=pre[0]){
            inr[n2++]=in[i];
        }
    }
    for(i=1;i<n;i++){
        if(i<n1+1){
            prel[m1++]=pre[i];
        }
        else {
            prer[m2++]=pre[i];
        }
    }
    T->lchild=CreatBiTree(prel,inl,n1);
    T->rchild=CreatBiTree(prer,inr,n2);
    return T;
}
int main(){
    int n;
    int preorder[N],inorder[N];
    cin>>n;
    BiTree T;
    for(int i=0;i<n;i++)
        cin>>preorder[i];
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    T=CreatBiTree(preorder,inorder,n);
    postTraverse(T);
    cout<<endl;
    return 0;
}
