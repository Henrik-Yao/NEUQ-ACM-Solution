#include <bits/stdc++.h>
using namespace std;
typedef struct BTNode{
    int level;
    int data;
    BTNode *lchild;
    BTNode *rchild;
}BTNode,*BiTree;
int maxlevel=0;
int sum[10001];
int num[10001];
BiTree CreatBiTree(int level){
    int n;
    cin>>n;
    if(n==0)
        return NULL;
    else {
        BiTree T=(BiTree)malloc(sizeof(BTNode));
        T->data=n;
        T->level=level;
        if(T->level>maxlevel)
            maxlevel=T->level;
        T->lchild=CreatBiTree(level+1);
        T->rchild=CreatBiTree(level+1);
        return T;
    }
}
void InorederTraverse(BiTree T){
    if(T==NULL)
        return;
    if(T->lchild==NULL&&T->rchild==NULL)
    {
        sum[T->level]+=T->data;
        num[T->level]++;
    }
    InorederTraverse(T->lchild);
    InorederTraverse(T->rchild);
}
int main(){
    BiTree T;
    T=CreatBiTree(0);
    InorederTraverse(T);
    int maxnum=-99999;
    int level=0;
    for(int i=0;i<=maxlevel;i++){
        if(num[i]!=0&&sum[i]>=maxnum){
            maxnum=sum[i];
            level=i;
        }
    }
    cout<<level<<endl;
    return 0;
}
