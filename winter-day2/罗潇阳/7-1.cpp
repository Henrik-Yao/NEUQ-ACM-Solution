#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *lson, *rson;
};

int sum = 0;
int level = 1;
int ans[1000] = {0};

Node* CreateTree() {
  int DATA;
  Node *newNode;
  cin >> DATA;
  if (DATA == 0) {
    newNode = NULL;
  } else {
    newNode = (Node*)malloc(sizeof(Node));
    newNode->val = DATA;
    newNode->lson = CreateTree();
    newNode->rson = CreateTree();
  }

  return newNode;
}

int findSum(Node* bt) {
  if (!bt) {
    return NULL;
  }

  if (!bt->lson && !bt->rson) {
    ans[level] = ans[level] + bt->val;
  }

  findSum(bt->lson);
  findSum(bt->rson);

  if (bt->lson && bt->rson) {
    level++;
  }

  return 1;
}

int main() {
  level = 1;
  Node* root = NULL;
  root = CreateTree();
  if (!root->lson && !root->rson) {
    cout << "0";
    return 0;
  }
  findSum(root);

  int temp = ans[0];
  int max = 0;
  for (int i = 1; i < level; i++) {
    if (temp < ans[i]) {
      temp = ans[i];
      max = i;
    }
  }

  cout << max << endl;

  return 0;
}
