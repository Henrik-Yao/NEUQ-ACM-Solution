#include <iostream>
using namespace std;
int a[101];
typedef struct tree{
    int data;
    tree *left,*right;
}tree;

tree *build()
{
    int Data;
    tree *t;
    cin>>Data;
    if(Data==0)
        t=NULL;
    else
    {
        t=new tree;
        t->data=Data;
        t->left=build();
        t->right=build();
    }
    return t;
}

int sum,num=1;

void find(tree *t)
{
    if(t){
        if(t->left==NULL&&t->right==NULL)
            a[num]+=t->data;
        find(t->left);
        find(t->right);
        if(t->left!=NULL&&t->right!=NULL)
            num++;
    }
    return;
}

int cmp(int *b,int k){
    int i,j;
    int temp = b[0],l = 0;
    for(j = 1;j < k;j++){
        if(b[j] >= temp){
            temp = b[j];
            l = j;
        }
    }
    return l;
}

int main(){
    tree  *T=NULL;
    T=build();
    if(T->left==NULL&&T->right==NULL)
    {
        cout<<0;
        return 0;
    }
    find(T);
    int i,j;
    int maxm=a[0],l=0;
    for(j=1;j<num;j++){
        if(a[j]>=maxm)
        {
            maxm=a[j];
            l=j;
        }
    }
    cout<<l<<endl;
    return 0;
}
