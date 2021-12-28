/*
#include<iostream>
using namespace std;

int former[11];
int middle[11];

typedef struct Bintree_Node {
	int data;
	Bintree_Node* left;
	Bintree_Node* right;
};

Bintree_Node* Build(int* Formerdata, int* Middledata, int num)
{
	if (Formerdata == NULL || Middledata == NULL || num <= 0)
		return NULL;
	Bintree_Node* root = new Bintree_Node;
	root->data = Formerdata[0];
	root->left = root->right = NULL;
	if (num == 1 && *Formerdata == *Middledata)
		return root;
	int left_num = 0;
	int* middle_root = Middledata;
	while (*middle_root != Formerdata[0] && middle_root <= (Middledata + num - 1))
	{
		middle_root++;
		left_num++;
	}
	if (*middle_root != Formerdata[0])
	{
		cout << "未找到根结点，输入错误" << endl;
		return NULL;
	}
	if (left_num > 0)
		root->left = Build(Formerdata + num - left_num, Middledata, left_num);
	if (num - left_num - 1 > 0)
		root->right = Build(Formerdata + 1, Middledata + left_num + 1, num - left_num - 1);
	return root;
}

void printing(Bintree_Node* node) {
	if (node == NULL) return;
	cout << node->data << " ";
	printing(node->left);
	printing(node->right);
}

void main()
{
	int nodeNum;
	cin >> nodeNum;
	for (int i = nodeNum - 1; i >= 0; i--) cin >> former[i];
	for (int i = 0; i < nodeNum; i++) cin >> middle[i];
	Bintree_Node* tree = NULL;
	tree = Build(former, middle, nodeNum);
	printing(tree);
}
*/