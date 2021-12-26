#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
    char data;
    struct node *left, *right;
} node, *bTree;

bool is_Valid(string post_order, string mid_order) //???????????
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
    int tag_ch;
    for (tag_ch = 0; tag_ch < mid_order.length(); tag_ch++)
    {
        if (mid_order[tag_ch] == ch)
        {
            break;
        }
    }
    string post_left = post_order.substr(0, tag_ch);
    string post_right = post_order.substr(tag_ch, post_order.length() - 1 - tag_ch);
    string mid_left = mid_order.substr(0, tag_ch);
    string mid_right = mid_order.substr(tag_ch + 1, mid_order.length() - 1);
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

bTree create_bTree(char *post, char *mid, int len)
{
    if(len < 1)
    {
        return NULL;
    }
    bTree btr = (bTree)malloc(sizeof(node));
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
    btr->right = create_bTree(post+i,mid+i+1,len-i-1);
    btr->left = create_bTree(post,mid,i);
    return btr;
}
int getHeight(bTree btr)
{
    if(!btr)
    {
        return 0;
    }
    return (getHeight(btr->left) > getHeight(btr->right)?getHeight(btr->left):getHeight(btr->right))+1;
}
void preorder(bTree btr)
{
    if(!btr)
    {
        return;
    }
    cout << btr->data;
    preorder(btr->left);
    preorder(btr->right);
}

void deleteorder(bTree btr)
{
    if(!btr)
    {
        return;
    }
    deleteorder(btr->left);
    deleteorder(btr->right);
    delete(btr);
}
int main()
{
    string mid_order, post_order;
    cin >> post_order >> mid_order;
    if (!is_Valid(post_order, mid_order))//???????
    {
        cout << "INVALID";
        continue;
    }
    char post[30], mid[30];
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
    bTree btr = create_bTree(post,mid,len);//?????
    cout << getHeight(btr)-1 << endl;//??????
    preorder(btr);
    deleteorder(btr);
    return 0;
}

