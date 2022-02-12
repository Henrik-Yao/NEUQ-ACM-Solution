#include<bits/stdc++.h>
using namespace std;
int n;
int pre[11],in[11];
//写在最前，pre【lpre】-》pre【lpre+i-lin】==in【i-1】及-》in【lin】的区间；
typedef struct hou{
    int data;
    struct hou *left,*right;
}hou,*linkhou;
//crea是一个构建二叉树的函数
void crea(linkhou &root,int pre[],int in[],int prel,int prer,int inl,int inr){
    if(prel<=prer){
        //先得到根节点
        root=new hou;
        root->data=pre[prel];
        root->left=NULL;
        root->right=NULL;
        //在in中定位根结点
        int j;
        for(j=inl;j<=inr;j++){
            if(in[j]==pre[prel])
            break;
        }
        //划分，继续自我调用
        crea(root->left,pre,in,prel+1,prel+j-inl,inl,j-1);
        crea(root->right,pre,in,prel+j-inl+1,prer,j+1,inr);
    }
}
void houxu(linkhou root){
    if(root!=NULL){
        houxu(root->left);
        houxu(root->right);
        cout<<root->data<<" ";

    }
}
int main(){
    cin>>n;
   for(int i=0;i<n;i++){
       cin>>pre[i];
   }
   for(int i=0;i<n;i++){
       cin>>in[i];
   }
   linkhou root;//这里的root将是我们二叉树的根节点；
   crea(root,pre,in,0,n-1,0,n-1);
   houxu(root);

    return 0;
}