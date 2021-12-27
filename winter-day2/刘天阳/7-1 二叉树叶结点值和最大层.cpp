#include <bits/stdc++.h>
using namespace std;
int b[1009];
typedef struct Node{
	Node *left,*right;
	int data;
}*LinkTreeNode,Node;

LinkTreeNode CreateTree(){
	int Data;
	LinkTreeNode node;
	cin >> Data;
	if(!Data) node = NULL;
	else {
		node = (LinkTreeNode)malloc(sizeof(Node));
		node->data = Data;
		node->left = CreateTree();
		node->right = CreateTree();
	}
	return node;
}
int sum = 0;
int ii = 1;
void add(LinkTreeNode BT){
	if(BT){
		
		if(BT->left == NULL && BT->right == NULL) b[ii] += BT->data;
		add(BT->left);
		add(BT->right);
		if(BT->left != NULL && BT->right != NULL) ii++;
	}
	return;
}

int main()
{
	LinkTreeNode T = NULL;
	T = CreateTree();
	
	if(T->left == NULL && T->right == NULL) 
	{
		cout << "0";
		return 0;
	}
	add(T);
	int maxx = b[1], l = 1;
//	cout << ii;
	for (int i = 1; i <= ii; i++)
	{
//		cout << "sdagsd";
		if(b[i] > maxx)
		{
			maxx = b[i];
			l = i;
		}
	}
		cout << l << endl;
	return 0;
}
