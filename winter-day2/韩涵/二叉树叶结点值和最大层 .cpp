#include<iostream>
#include<math.h>
using namespace std;

int a[105] = { 0 };
int num = -1;
int plie[105] = { 0 };
int maxp = 0,minp = 32767;

typedef struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int* a,int pli) {
    if (a[++num] == 0) return NULL;
    Node* node = new Node;
    node->data = a[num];
    node->left = create(a,pli + 1);
    node->right = create(a,pli + 1);
    if (node->left == NULL && node->right == NULL) {
        plie[pli] += node->data;
        maxp = maxp > pli ? maxp : pli;
        minp = minp < pli ? minp : pli;
    }
    return node;
}

int main() {
    for (int i = 0; cin >> a[i]; i++);
    Node* root = create(a, 0);
    int ans = 0,sum = -32767;
    for (int i = minp; i <= maxp; i++) {
        if (plie[i] >= sum) {
            sum = plie[i];
            ans = i;
        }
    }
    cout << ans;
}