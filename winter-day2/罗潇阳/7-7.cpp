#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *lson;
  struct Node *rson;
};

Node *createBT(int *pre, int *in, int n) {
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
  b->lson = createBT(pre + 1, in, k);
  b->rson = createBT(pre + 1 + k, p + 1, n - k - 1);
  return b;
}

void showBTPreOrder(Node *b) {
  if (b != NULL) {
    cout << b->data;
    showBTPreOrder(b->lson);
    showBTPreOrder(b->rson);
  }
}

void showBTInOrder(Node *b) {
  if (b != NULL) {
    showBTInOrder(b->lson);
    printf("%c", b->data);
    showBTInOrder(b->rson);
  }
}

void FloorPrint_QUEUE(Node *Tree) //层序遍历_队列实现
{
  queue<Node *> q;
  if (Tree != NULL) {
    q.push(Tree);
  }

  while (q.empty() == false) {
    cout << q.front()->data << " ";

    if (q.front()->lson != NULL) {
      q.push(q.front()->lson);
    }

    if (q.front()->rson != NULL) {
      q.push(q.front()->rson);
    }
    q.pop();
  }
}

int main() {
  Node *b = NULL;
  int pre[1000];
  int mid[1000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pre[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> mid[i];
  }
  b = createBT(pre, mid, n);
  FloorPrint_QUEUE(b);

  return 0;
}
