#include <bits/stdc++.h>
using namespace std;
typedef struct btree
{
    int data;
    btree *lchild,*rchild;
}BiTNode, *BiTree;
void create_tree(BiTree& t, int* back, int* mid, int n)
{
    int num;
    int *ptr;
    if(n<=0)
    {
    	t=NULL;
    	return ;
	}
	t=new btree;
	ptr=mid;
	while(*ptr!=back[n-1]) ptr++;
	t->data=*ptr;
	num=ptr-mid;
	create_tree(t->lchild,back,mid,num);
	create_tree(t->rchild,back+num,mid+num+1,n-num-1);
}
void search_front(BiTree t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        search_front(t->lchild);
        search_front(t->rchild);
    }
}
int main()
{
	int n,back[11],mid[11];
	cin>>n;
	BiTree t;
	for(int i=0;i<n;i++) cin>>back[i];
	for(int i=0;i<n;i++) cin>>mid[i];
	create_tree(t,back,mid,n);
	search_front(t);
}
