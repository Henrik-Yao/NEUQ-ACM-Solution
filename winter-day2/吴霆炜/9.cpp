#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left, *right;
}node,*BiTree;

BiTree create_BiTree(int *post, int *mid, int len)
{
    if(len < 1)
    {
        return NULL;
    }
    BiTree btr = (BiTree)malloc(sizeof(node));
    btr->data = post[len-1];
    btr->left = btr->right = NULL;
    int i;
    for(i = 0;i < len;i++)
    {
        if(mid[i] == post[len-1])
        {
            break;
        }
    }
    btr->right = create_BiTree(post+i,mid+i+1,len-i-1);
    btr->left = create_BiTree(post,mid,i);
    return btr;
}
void preorder(BiTree btr)
{
    if(!btr)
    {
        return;
    }
    cout << btr->data << " " ;
    preorder(btr->left);
    preorder(btr->right);
}

int main()
{
    int len;
	int post[100], mid[100];
	cin>>len;
	for(int i = 0;i < len;i++)cin>>post[i];
	for(int i = 0;i < len;i++)cin>>mid[i];
    BiTree btr = create_BiTree(post,mid,len);
    preorder(btr);
	return 0;
}
