#include<iostream>
#include<vector>
using namespace std;
vector<char>vec;
bool flag=1;
struct node
{
    char x;
    node *left;
    node *right;
};
node* create(char post[],char mid[],int len)
{
    if(len==0) return NULL;
    node* tree =new node;
    tree->x=post[len-1];
    int i=0;
    for(i=0;i<len;i++)
        if(post[len-1]==mid[i]) break;
    if(i==len)
    {
        flag=0;
        return NULL;
    }
    else
    {
        vec.push_back(tree->x);
        tree->left=create(post,mid,i);
        tree->right=create(post+i,mid+i+1,len-i-1);
    }
    return tree;
}

int get_high(node* tree)
{
    if(tree==NULL) return 0;
    int l=get_high(tree->left);
    int r=get_high(tree->right);
    return max(l,r)+1;
}

int main()
{
    string str1,str2;
    while (cin>>str1>>str2)
    {
        flag=1;
        vec.clear();
        int len=str1.length();
        char post[100],mid[100];
        for(int i=0;i<len;i++)
        {
            post[i]=str1[i];
            mid[i]=str2[i];
        }
        node* tree=create(post,mid,len);
        if(flag==1)
        {
            cout<<get_high(tree)-1<<"\n";
            for(int i=0;i<vec.size();i++)
                cout<<vec[i];
            cout<<"\n";
        }
        else cout<<"INVALID\n";
    }
}
