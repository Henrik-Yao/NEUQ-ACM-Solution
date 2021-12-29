#include <bits/stdc++.h>
using namespace std;
typedef struct BiTree{
	int data;
	BiTree *lchild,*rchild;
}Tree,*BiTre;
int tre[1001];
BiTre CreateTree()
{
	int c;
	cin>>c;
	BiTre t;
	if(c==0) t=NULL;
	else
	{
		t=(BiTre)malloc(sizeof(Tree));
		t->data=c;
		t->lchild=CreateTree();
		t->rchild=CreateTree();
	}
	return t;
}
int sum=0,i=1;
void calsum(BiTre T)
{
	if(T)
	{
		if(T->lchild==NULL&&T->rchild==NULL) tre[i]+=T->data;
		calsum(T->lchild);
		calsum(T->rchild);
		if(T->lchild!=NULL&&T->rchild!=NULL) i++;
	}
	return;
}
int main()
{
	BiTre str;
	int max=tre[0],max1=0;
	str=CreateTree();
	if(str->lchild==NULL&&str->rchild==NULL) cout<<"0";
	else
	{
		calsum(str);
		for(int j=1;j<i;j++)
		{
			if(tre[j]>=max)
			{
				max=tre[j];max1=j;
			}
		}
		cout<<max1;
	}
	return 0;
}
