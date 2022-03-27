#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *lson;
  struct Node *rson;
};

Node *buildTree(int *pre, int *in, int n) {
  Node *b;
  int *p;
  int k;
  if (n <= 0)
    return NULL;
  b = (Node *)malloc(sizeof(Node));
  b->data = *pre;
  int j = 0;
  for (p = in; p < in + n; p++) {
    if (*p == *pre)
      break;
  }
  k = p - in;
  b->lson = buildTree(pre + 1, in, k);
  b->rson = buildTree(pre + 1 + k, p + 1, n - k - 1);
  return b;
}

void showTreePreOrder(Node *b) {
  if (b != NULL) {
    cout << b->data;
    showTreePreOrder(b->lson);
    showTreePreOrder(b->rson);
  }
}

void showTreeInOrder(Node *b) {
  if (b != NULL) {
    showTreeInOrder(b->lson);
    printf("%c", b->data);
    showTreeInOrder(b->rson);
  }
}

void OrderTraverse(Node *t) {
  if (t == NULL) {
    return;
  }
  OrderTraverse(t->lson);
  OrderTraverse(t->rson);
  cout << t->data << " ";
}

int pre[1000];
int mid[1000];
int n;

int main() {
  Node *b = NULL;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pre[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> mid[i];
  }
  b = buildTree(pre, mid, n);
  OrderTraverse(b);

  return 0;
}
