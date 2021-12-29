#include<bits/stdc++.h>
using namespace std;
#define M 20
int a[M];
int b[M];
typedef struct leaf {
	int data;
	struct leaf* lchild;
	struct leaf* rchild;
}Leaf, * lpLeaf;
//这个值的作用是为当前申请的空间找到对应的先序序列位置
//也就是找到当前序列中的根节点位置
static int pos = 0;
//由先序遍历(a)和中序遍历(b)创建二叉树
lpLeaf create(int a[], int b[], int start, int end) {
	if (start <= end) {
		int i = 0;
		lpLeaf p = (lpLeaf)malloc(sizeof(Leaf));
		p->data = a[pos];
		for (i = start; i <= end; i++)
			if (b[i] == p->data)
				break;
		pos++;//查找a中找到的根节点在b中的位置，一定能找到，找不到就错了
		//查找顺序是根->左孩子->右孩子，所以要加一
		//反之如果是后序则pos开始要置最大值pos--
		//因为如果是后序的话（从后向前）顺序是根->右孩子->左孩子，所以p的右孩子赋值要在左孩子前面
		p->lchild = create(a, b, start, i - 1);
		p->rchild = create(a, b, i + 1, end);
		return p;
	}
	return NULL;
}
//后序遍历
void look(lpLeaf root)
{
	queue<lpLeaf> q;
	q.push(root);

	while(!q.empty())
    {
        lpLeaf op = q.front();
        q.pop();
        cout<<op->data<<" ";
        if(op->lchild!=NULL)
        {
            q.push(op->lchild);
        }
        if(op->rchild!=NULL)
        {
            q.push(op->rchild);
        }
    }
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    lpLeaf tree = create(a,b,0,n-1);
    look(tree);

	return 0;
}

