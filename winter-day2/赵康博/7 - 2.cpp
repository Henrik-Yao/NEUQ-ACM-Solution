#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
    char data;
    tree *lChild,*rChild;
}*Tree;
bool judge(string a,string b)
{
    if(a.length()==0&&b.length()==0)return true;
    else if(a.length()!=b.length())return false;
    char t = a[a.length()-1];
    int i;
    for(i = 0; i < b.length(); i++)
    {
        if(t==b[i])break;
    }
    string a1 = a.substr(0,i);
    string b1 = b.substr(0,i);
    string a2 = a.substr(i,a.length()- 1 - i);
    string b2 = b.substr(i+1);
    for(int j = 0; j < a1.length(); j++)
        if(b1.find(a1[j])==-1)return false;
    for(int j = 0; j < a2.length(); j++)
        if(b2.find(a2[j])==-1)return false;
    return judge(a1,b1)&& judge(a2,b2);
}
Tree rebuild(string a,string b)
{
    if(a.length()==0)return nullptr;
    Tree p = (Tree) malloc(sizeof (tree));
    p->data = a[a.length()-1];
    int i;
    for(i = 0; i < b.length(); i++)
    {
        if(p->data==b[i])break;
    }
    string a1 = a.substr(0,i);
    string b1 = b.substr(0,i);
    string a2 = a.substr(i,a.length()- 1 - i);
    string b2 = b.substr(i+1);
    p->lChild = rebuild(a1,b1);
    p->rChild = rebuild(a2,b2);
    return  p;
}
int getHigh(Tree a)
{
    if(a== nullptr)return 0;
    int left = getHigh(a->lChild);
    int right = getHigh(a->rChild);
    return  (left > right ? left : right) + 1;
}
void visit(Tree p) {
    if (!p)
        return;
    cout<<p->data;
    visit(p->lChild);
    visit(p->rChild);
}

int main() {
    Tree p;
    string a,b;
    while (cin>>a>>b)
    {
        if(!judge(a,b))
        {
            cout<<"INVALID"<<endl;
            continue;
        }
        p = rebuild(a,b);
        int t = getHigh(p) - 1;
        cout<<t<<endl;
        visit(p);
        cout<<endl;
    }
    return 0;
}
