#include<bits/stdc++.h>
using namespace std;
int  a[110];
int sum=0,ii=1;
//定义结点
typedef struct node{
    int date;
    struct node *left,*right;
}node,*linknode;
//根据前序序列创建一颗树
linknode crea(){
    linknode r;
    int num;
    scanf("%d",&num);
    if(num==0){
        r=NULL;
    }
    else{
        r=new node;
        r->date=num;
        r->left=crea();
        r->right=crea();
    }
return r;
}
//求叶子结点的和和最大值的那层
void p(linknode t){
    if(t){
        if(t->left==NULL&&t->right==NULL)
            a[ii]+=t->date;
        
            p(t->left);
            p(t->right);
        if(t->left!=NULL&&t->right!=NULL){
            ii++;
        }
    }

}
int compare(int b[],int k){
        int i,j,temp=a[0],lin=0;
        for(j=1;j<k;j++){
            if(temp<=a[j]){
                temp=a[j];
                lin=j;
            }
        }
        return lin;
}
int main(){
    linknode l=NULL;
    l=crea();

    if(l->left==NULL&&l->right==NULL){
            cout<<"0"<<endl;return 0;
        }//根就是叶

    p(l);
    
    int lin=compare(a,ii);
    cout<<lin<<endl;
    
    
    return 0;
}