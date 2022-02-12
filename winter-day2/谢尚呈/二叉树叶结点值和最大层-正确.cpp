#include<iostream>
using namespace std;

int sum[105];//sum[i]�ǵ�i��Ҷ�ӽ��ĺ�
int num[105];//num[i]�ǵ�i��Ҷ�ӽ�������
int deep=0;//������������

struct node
{
	int data;
	int level;
	node* left;
	node* right;
	bool leaf(void)
	{
		return left==NULL&&right==NULL;
	}
};

node* struct_tree(int level)
{
	int n;
	scanf("%d", &n);
	if (n == 0)
		return NULL;
	node* root=new node;
	root->data=n;
	root->level=level;
	if (root->level>deep)
		deep=root->level;
	root->left=struct_tree(level+1);
	root->right=struct_tree(level+1);
	if(root->leaf())
	{
		sum[root->level]+=root->data;
		num[root->level]+=1;
	}
	return root;
}
int main()
{
	node* root=struct_tree(0);
	int maxnum=-1000,level=-1;
	for (int i=0; i<=deep; i++)
	{
		if (sum[i]>=maxnum&&num[i]!=0)
		{
			maxnum = sum[i];
			level = i;
		}
	}
	printf("%d", level);
	return 0;
}

