#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int b[100];
int max_ = 0,sum[N];

typedef struct BitNode{
    int data;
    BitNode *LeftChild,*RightChild;
}*BiTree;

BiTree CreateBiTree(){
    int a;
    BiTree temp;
    cin >> a;
    if(a == 0){
        temp = NULL;
    }
    else{
        temp = new BitNode();
        temp->data = a;
        temp->LeftChild = CreateBiTree();
        temp->RightChild = CreateBiTree();
    }
    return temp;
}

//int sum = 0;
int x = 1;

void PreVis(BiTree Tree){
    if (Tree)
    {
        if (Tree->LeftChild == NULL && Tree->RightChild == NULL)
            b[x] += Tree->data;
        PreVis(Tree->LeftChild);
        PreVis(Tree->RightChild);
        if (Tree->LeftChild != NULL && Tree->RightChild != NULL)
            x++;
    }
    return;
}

int compare(int *a, int k)
{
    int i, j, temp = a[0], l = 0;
    for (j = 1; j < k; j++)
    {
        if (temp <= a[j])
        {
            temp = a[j];
            l = j;
        }
    }
    return l;
}

int main(){
    BiTree Tree = CreateBiTree();
    PreVis(Tree);
    cout << compare(b,x);
    return 0;
}
