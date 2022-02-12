#include <bits/stdc++.h>
using namespace std;
#define maxn 100

int a[maxn];
typedef struct BiTreeNode{
    int data;
    struct BiTreeNode *l_child,*r_child;
}BiTreeNode,*LinkBiTreeNode;

LinkBiTreeNode CreateBitree(){
    int Data;
    LinkBiTreeNode node;
    scanf("%d",&Data);
    if(!Data)
    node = NULL;
    else{
        node = (LinkBiTreeNode)malloc(sizeof(BiTreeNode));
        node -> data = Data;
        node -> l_child = CreateBitree();
        node -> r_child = CreateBitree();
    }
    return node;
}

int sum,cnt = 1;

void work(LinkBiTreeNode BT){
    if(BT){
        if(BT -> l_child == NULL && BT -> r_child == NULL)
            a[cnt] += BT -> data;
        work(BT -> l_child);
        work(BT -> r_child);
        if(BT -> l_child != NULL && BT -> r_child != NULL)cnt++;
    }
    return;
}

int cmp(int *b,int k){
    int i,j;
    int temp = b[0],l = 0;
    for(j = 1;j < k;j++){
        if(b[j] >= temp){
            temp = b[j];
            l = j;
        }
    }
    return l;
}

int main(){
    LinkBiTreeNode T = NULL;
    T = CreateBitree();
    if(T -> l_child == NULL && T -> r_child == NULL){
        puts("0");
        return 0;
    }
    work(T);
    int pos = cmp(a,cnt);
    cout<<pos<<endl;
    return 0;
}