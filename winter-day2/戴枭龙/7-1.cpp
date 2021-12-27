#include <bits/stdc++.h>
using namespace std;

struct Tree_Node {
	int data;
	int level;
	Tree_Node *lchild;
	Tree_Node *rchild;
};
int sum[105], num[105], maxlevel, maxnum = -10000000;

void createTree(Tree_Node *&t, int m) {//按照先序遍历创建二叉树
	int a;
	cin >> a;
	if (a == 0) {
		t = NULL;
		return;
	} else {
		t = new Tree_Node; //为t开辟空间
		t->data = a;
		t->level = m;
		maxlevel = max(maxlevel, m);
		createTree(t->lchild, m + 1);
		createTree(t->rchild, m + 1);
	}
}

void getsum(Tree_Node *t) {
	if (t == NULL)
		return;
	if (t->lchild == NULL && t->rchild == NULL) {
		sum[t->level] += t->data;
		num[t->level]++;
	}
	getsum(t->lchild);
	getsum(t->rchild);
}

int main() {
	Tree_Node *T;
	createTree(T, 0);
	getsum(T);
	int level = -1;
	for (int i = 0; i <= maxlevel; i++) {
		if (sum[i] >= maxnum && num[i] != 0) {
			maxnum = sum[i];
			level = i;
		}
	}
	cout << level;
	return 0;
}