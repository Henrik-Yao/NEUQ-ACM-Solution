/*
#include<iostream>
using namespace std;

typedef struct Node {
    int elem;
    struct Node* dad;
    struct Node* son;
};

Node* create(int num) {
    Node* nod = NULL;
    nod = (Node*)malloc(sizeof(Node));
    nod->elem = 1;
    Node* ret = nod;
    for (int i = 2; i <= num; i++) {
        Node* q = NULL;
        q = (Node*)malloc(sizeof(Node));
        q->elem = i;
        q->dad = nod;
        nod->son = q;
        nod = nod->son;
    }
    ret->dad = nod;
    nod->son = ret;
    return ret;
}

void deletel(Node* del) {
    Node* temp1 = NULL,*temp2 = NULL;
    temp1 = del->son;
    temp2 = del->dad;
    temp2->son = temp1;
    temp1->dad = temp2;
    free(del);
}

bool black(Node* temp) {
    return temp->dad == temp;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    Node* node = create(n);
    Node* temp = NULL;
    while (!black(node)) {
        node = node->dad;
        if(temp != NULL)deletel(temp);
        if (black(node)) break;
        for (int i = 0; i < m - 2; i++) node = node->dad;
        cout << node->elem<< " ";
        temp = node;
        node = node->son;
        deletel(temp);
        for (int i = 0; i < k - 2; i++) {
            node = node->son;
        }
        cout << node->elem<<" ";
        temp = node;
    }
}
*/