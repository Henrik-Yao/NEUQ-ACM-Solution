#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  int num;
  Node *lson, *rson;
};

int t;

void createTree(Node *&t, int *a, int num, int n) {
  if (a[num] == 0) {
    t = NULL;
    return;
  } else {
    t = new Node;
    t->data = a[num];
  }
  if (num * 2 <= n) {
    createTree(t->lson, a, num * 2, n);
  } else
    t->lson = NULL;
  if (num * 2 + 1 <= n) {
    createTree(t->rson, a, num * 2 + 1, n);
  } else
    t->rson = NULL;
}

void inorder1(Node *t) {
  if (t == NULL)
    return;
  inorder1(t->lson);
  cout << t->data << " ";
  inorder1(t->rson);
}

void inorder2(Node *t) {
  if (t == NULL)
    return;
  inorder2(t->lson);
  cout << " " << t->data;
  inorder2(t->rson);
}

int getdeep(Node *t) {
  int l, r;
  if (t == NULL)
    return 0;
  else {
    l = getdeep(t->lson);
    r = getdeep(t->rson);
    if (l > r)
      return l + 1;
    else
      return r + 1;
  }
}

int n;
int a[10000];

int main() {
  cin >> t;
  while (t--) {
    Node *root;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    createTree(root, a, 1, n);
    inorder1(root->lson);
    cout << root->data;
    inorder2(root->rson);
    cout << endl;
    cout << getdeep(root) << endl;
  }
  return 0;
}
