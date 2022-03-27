/*#include<iostream>
#include<queue>
using namespace std;

typedef struct Bintree_Node {
	int data;
	Bintree_Node* left;
	Bintree_Node* right;
};

int former[11];
int middle[11];
queue <Bintree_Node*> nod;


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
	if (*middle_root != Formerdata[0]) return NULL;
	if (left_num > 0)
		root->left = Build(Formerdata + 1, Middledata, left_num);
	if (num - left_num - 1 > 0)
		root->right = Build(Formerdata + left_num + 1, Middledata + left_num + 1, num - left_num - 1);
	return root;
}

void printing() {
	while (!nod.empty()) {
		Bintree_Node* temp = nod.front();
		cout << temp->data <<" ";
		if (temp->left != NULL)nod.push(temp->left);
		if (temp->right != NULL)nod.push(temp->right);
		nod.pop();
	}
}

int main()
{
	int nodeNum;
	cin >> nodeNum;
	for (int i = 0; i < nodeNum; i++) cin >> former[i];
	for (int i = 0; i < nodeNum; i++) cin >> middle[i];
	Bintree_Node* tree = NULL;
	tree = Build(former, middle, nodeNum);
	nod.push(tree);
	printing();
}
*/