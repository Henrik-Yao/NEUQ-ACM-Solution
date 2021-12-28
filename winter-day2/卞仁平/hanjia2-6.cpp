#include<bits/stdc++.h>
using namespace std;
vector<int>a;
typedef struct tree
{
    tree *l;
    tree *r;
};
tree *order(int qian[],int zhong[],int n)
{
    if(n==0)return NULL;
    tree* x=new tree;
    int i;
    for(i=0;i<n;i++)
    {
        if(qian[0]==zhong[i])break;
    }
    if(i==n) return NULL;
	a.insert(a.begin(),qian[0]);
	x->r = order(qian+i+1,zhong+i+1,n-i-1);
	x->l = order(qian+1,zhong,i);
	return x;
    
}

int main()
{
    int n;cin>>n;
    int qian[n],zhong[n];
    for(int i=0;i<n;i++)cin>>qian[i];
    for(int i=0;i<n;i++)cin>>zhong[i];
    tree *x=order(qian,zhong,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}