/*#include<iostream>
#include<math.h>
using namespace std;

int a[1005] = { 0 };
int num1 = 0;

typedef struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* create(int* a, int num) {
	if (a[num] == 0) return NULL;
	Node* root = new Node;
	root->data = a[num];
	root->left = create(a, num * 2);
	root->right = create(a, num * 2 + 1);
	num1++;
	return root;
}

void printing(Node* node) {
	if (node == NULL) return;
	printing(node->left);
	cout << node->data;
	if (num1 > 1) {
		num1--;
		cout << " ";
	}
	printing(node->right);
}

int main() {
	int len, t;
	cin >> t;
	while (t--) {
		cin >> len;
		for (int i = 1; i <= len; i++) cin >> a[i];
		for (; a[len] == 0; len--);
		int num = 0, times = 0;
		for (num = 0; num < len; times++) num += pow(2, times);
		Node* root = create(a, 1);
		printing(root);
		cout << endl;
		for (int i = 0; i <= len; i++) a[i] = 0;
		num1 = 0;
		cout << times << endl;
	}
}*/