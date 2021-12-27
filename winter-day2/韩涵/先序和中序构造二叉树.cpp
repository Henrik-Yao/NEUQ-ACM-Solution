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
	//先序遍历，第一个值就是根结点
	Bintree_Node* root = new Bintree_Node;
	root->data = Formerdata[0];
	root->left = root->right = NULL;
	//如果只有一个结点
	if (num == 1 && *Formerdata == *Middledata)
		return root;

	//在中序序列中找到根结点
	int left_num = 0;//左子树的结点总数
	int* middle_root = Middledata;//中序序列中的根结点
	//第二个条件：循环要在Middledata中进行
	while (*middle_root != Formerdata[0] && middle_root <= (Middledata + num - 1))
	{
		middle_root++;
		left_num++;
	}
	if (*middle_root != Formerdata[0])//未找到根结点，输入错误
	{
		cout << "未找到根结点，输入错误" << endl;
		return NULL;
	}
	//创建左子树
	if (left_num > 0)
		root->left = Build(Formerdata + 1, Middledata, left_num);//Formerdata+1即为左子树的前序序列的开始
	//创建右子树
	if (num - left_num - 1 > 0)
		root->right = Build(Formerdata + left_num + 1, Middledata + left_num + 1, num - left_num - 1);
	return root;
}

void printing(Bintree_Node* node) {
	if (node == NULL) return;
	printing(node->left);
	printing(node->right);
	cout << node->data << " ";
}

void main()
{
	int nodeNum;
	cin >> nodeNum;
	for (int i = 0; i < nodeNum; i++) cin >> former[i];
	for (int i = 0; i < nodeNum; i++) cin >> middle[i];
	Bintree_Node* tree = NULL;
	tree = Build(former, middle, nodeNum);
	printing(tree);
}
*/