#include <bits/stdc++.h>
using namespace std;
const int maxn=123456;

typedef struct Bitree
{
	int data;
	 Bitree *lchild,*rchild;
} *List;

List create(int *pre,int *in,int n)
{
	List node=(List)malloc(sizeof(List));
	node->data=pre[0];
	node->lchild=NULL;
	node->rchild=NULL;
	if(n==1) return node;
	int mid=0,rlen;
	while(in[++mid]!=pre[0]);
	rlen=n-mid-1;
	node->lchild=create(pre+1,in,mid);
	node->rchild=create(pre+1+mid,in+1+mid,rlen);
	return node;
}

void print(List node)
{
	if(!node) return;
	print(node->lchild);
	print(node->rchild);
	printf("%d ",node->data);
}

int main()
{
	int n,i;
	int pre[maxn],in[maxn];
	cin>>n;
	for(i=0;i<n;i++) cin>>pre[i];
	for(i=0;i<n;i++) cin>>in[i];
	List temp=create(pre,in,n);
	print(temp);
	return 0;
}
