#include <bits/stdc++.h>
using namespace std;
string pre[11], mid[11], post[11];

struct node {
	string data;
	node *left;
	node *right;
};
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
	for (int i = 1; i <= n; i++)
		cin >> pre[i];
	for (int i = 1; i <= n; i++)
		cin >> mid[i];
	node *root = get_tree(1, 1, n);
	queue<node *>q;
	q.push(root);
	while (!q.empty()) {
		cout << q.front()->data << " ";
		if (q.front()->left != NULL)
			q.push(q.front()->left);
		if (q.front()->right != NULL)
			q.push(q.front()->right);
		q.pop();
	}
	return 0;
}