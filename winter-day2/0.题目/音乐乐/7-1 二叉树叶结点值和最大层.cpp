#include<bits/stdc++.h>
using namespace std;

int sum[101],total,depth=1;

typedef struct Binary_tree_node
{
	int data;
	struct Binary_tree_node *left_leave,*right_leave;
}Binary_tree_node,*Link;

Link create()
{
	int num;
	Link node;
	cin>>num;
	if(!num)
		node=NULL;
	else
	{
		node=(Link)malloc(sizeof(Binary_tree_node));
		node->data=num;
		node->left_leave=create();
		node->right_leave=create();
	}
	return node;
}

void fuc(Link BT)
{
	if(BT)
	{
		if(BT->left_leave==NULL&&BT->right_leave==NULL)
			sum[depth]+=BT->data;
		fuc(BT->left_leave);
		fuc(BT->right_leave);
		if(BT->left_leave!=NULL&&BT->right_leave!=NULL)
			depth++;
	}
	return;
}

int cmp(int *arr,int depth)
{
	int i,temp=arr[0],index=0;
	for(i=1;i<depth;i++)
	{
		if(arr[i]>=temp)
		{
			temp=arr[i];
			index=i;
		}
	}
	return index;
}
int main()
{
	Link tree=NULL;
	tree=create();
	fuc(tree);
	int ans=cmp(sum,depth);
	cout<<ans;
	return 0;
}
