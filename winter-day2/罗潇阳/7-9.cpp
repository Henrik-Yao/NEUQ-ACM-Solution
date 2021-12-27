#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *lson, *rson;
};

int n;
int rear[10000];
int mid[10000];

void InitTree(Node *&t, int *rear, int *mid, int n) {
  int num;
  int *p;
  if (n <= 0) {
    t = NULL;
    return;
  }
  t = new Node;
  p = mid;
  while (*p != rear[n - 1]) {
    p++;
  }
  t->data = *p;
  num = p - mid;
  InitTree(t->lson, rear, mid, num);
  InitTree(t->rson, rear + num, mid + num + 1, n - num - 1);
}

void preorder(Node *t) {
  if (t == NULL) {
    return;
  }

  cout << t->data << " ";
  preorder(t->lson);
  preorder(t->rson);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> rear[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> mid[i];
  }

  Node *root;
  InitTree(root, rear, mid, n);
  preorder(root);

  return 0;
}
