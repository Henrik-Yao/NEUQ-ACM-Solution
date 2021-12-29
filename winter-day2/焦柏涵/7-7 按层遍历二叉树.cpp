#include <bits/stdc++.h>
using namespace std;
typedef struct BTree{
	int data;
	BTree *lchild,*rchild; 
}*tree;
int front[10],mid[10];
tree t;
void createTree(tree& t, int f1, int f2, int m1,int m2)
{
    int i;
    t=new BTree;
    if(f1>f2)
    {
        t=NULL;
        return;
    }
    t->data=front[f1]; 
    for(i=m1;i<=m2;i++)
    {
        if(mid[i]==front[f1])  
        {
            break;
        }
    }             
    createTree(t->lchild,f1+1,f1+i-m1,m1,i-1);
    createTree(t->rchild,f1+i-m1+1,f2,i+1,m2);
}
void search(tree t)
{
	queue <tree> tre;
	tre.push(t);
	while(!tre.empty()&&tre.front())
	{
		cout<<tre.front()->data<<" ";
		if(tre.front()->lchild!=NULL)
		{
			tre.push(tre.front()->lchild);
		}
		if(tre.front()->rchild!=NULL)
		{
			tre.push(tre.front()->rchild);
		}
		tre.pop();
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>front[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>mid[i];
	}
	createTree(t,0,n-1,0,n-1);
	search(t);
	return 0;
}
