#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    char data;
    struct node *left, *right;
}node,*BiTree;

bool is_Valid(string post_order, string mid_order) 
{
    if (post_order.length() == 0 && mid_order.length() == 0)
    {
        return true;
    }
    if (post_order.length() != mid_order.length())
    {
        return false;
    }
    char ch = post_order[post_order.length() - 1];
    int pos_ch;
    for (pos_ch = 0; pos_ch < mid_order.length(); pos_ch++)
    {
        if (mid_order[pos_ch] == ch)
        {
            break;
        }
    }
    string post_left = post_order.substr(0, pos_ch);
    string post_right = post_order.substr(pos_ch, post_order.length() - 1 - pos_ch);
    string mid_left = mid_order.substr(0, pos_ch);
    string mid_right = mid_order.substr(pos_ch + 1, mid_order.length() - 1);
    for (int i = 0; i < post_left.length(); i++)
    {
        if (mid_left.find(post_left[i]) == -1)
        {
            return false;
        }
    }
    for (int i = 0; i < post_right.length(); i++)
    {
        if (mid_right.find(post_right[i]) == -1)
        {
            return false;
        }
    }

    return is_Valid(post_left, mid_left) && is_Valid(post_right, mid_right);
}

BiTree create_BiTree(char *post, char *mid, int len)
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
int getHeight(BiTree btr)
{
    if(!btr)
    {
        return 0;
    }
    return (getHeight(btr->left) > getHeight(btr->right)?getHeight(btr->left):getHeight(btr->right))+1;
}
void preorder(BiTree btr)
{
    if(!btr)
    {
        return;
    }
    cout << btr->data;
    preorder(btr->left);
    preorder(btr->right);
}

void _delete(BiTree btr)
{
    if(!btr)
    {
        return;
    }
    _delete(btr->left);
    _delete(btr->right);
    delete(btr);
}
int main()
{
    string mid_order, post_order;
    while(getline(cin,post_order),getline(cin,mid_order)){
    char post[30], mid[30];
    memset(post,'\0',sizeof(post));
    memset(mid,'\0',sizeof(mid));
    if (!is_Valid(post_order, mid_order))
    {
        puts("INVALID");
        continue;
    }
    int t = 0, len = post_order.length();
    for (int i = 0; i < len; i++)
    {
        post[t++] = post_order[i];
    }
    t = 0;
    for (int i = 0; i < len; i++)
    {
        mid[t++] = mid_order[i];
    }
    BiTree btr = create_BiTree(post,mid,len);
    cout << getHeight(btr)-1 << endl;
    preorder(btr);
    puts("");
    _delete(btr);
    }
    return 0;
}
