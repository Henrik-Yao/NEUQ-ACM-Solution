/*
7-1 ������Ҷ���ֵ������
��֪һ�÷ǿն���������������Ϊ������0�����������д�����ҳ��ö�������Ҷ�������ֵ֮�����Ĳ㡣
�����ʽ:
����Ϊһ���ÿո���������������������100������ʾ����ָ����Ϣ�Ķ������ȸ����С�
�����ʽ:
���Ϊһ����������ʾҶ�������ֵ֮�����Ĳ㣬������ڶ�����������Ĳ㣬�����������һ�㡣
��������1:
1 2 0 0 3 0 0
�������1
1
��������2:
1 -2 0 0 3 -1 0 0 -1 0 0
�������2:
2
*/
#include <bits/stdc++.h>
using namespace std;
int b[100]={0};
typedef struct node{
    int value;
    struct node *left, *right;
}*tree;
tree cr(){
    int Data;
    tree node;
    cin>>Data;
    if(!Data) node=NULL;
    else{
        n=(linknode)malloc(sizeof(node));
        n->data=Data;
        n->lchild=cr();
        n->rchild=cr();
    }
    return n;
}
int sum=0,x=1;
void f(tree n){
    if(n){
        if(!n->left && !n->right) b[x]+=n->data;
        f(n->lfet);f(n->right);
        if(n->left && n->right) x++;
    }
}
int compare(int *a,int k){
    int temp=a[0],l=0;
    for(int i=1;i<k;i++)
        if(temp<=a[i]){
            temp=a[i];l=i;
        }
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    tree a=NULL;
    a=cr();f(a);
    cout<<compare(b,x)<<endl;
    return 0;
}

