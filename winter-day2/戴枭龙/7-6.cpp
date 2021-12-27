#include <bits/stdc++.h>
using namespace std;
string pre[11], mid[11], post[11];

struct node {
	string data;
	node *left;
	node *right;
};
void get_post(node *root) {
	if (root != NULL) {
		get_post(root->left);
		get_post(root->right);
		cout << root->data << " ";
	}
}
node *get_tree(int i, int j, int len) {
	if (len <= 0)
		return NULL;
	node *tree = new node;
	tree->data = pre[i];
	int p;
	for (p = 1; p <= 11; p++)
		if (mid[p] == pre[i])
			break;
	tree->left = get_tree(i + 1, j, p - j);
	tree->right = get_tree(i + (p - j) + 1, p + 1, len - 1 - (p - j));
	return tree;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)//输入前序遍历对应顺序
		cin >> pre[i];
	for (int i = 1; i <= n; i++)//输入中序遍历对应顺序
		cin >> mid[i];
	node *root = get_tree(1, 1, n);//获得根节点
	get_post(root);
	return 0;
}