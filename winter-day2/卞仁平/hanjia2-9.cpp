#include<bits/stdc++.h>
using namespace std;
//vector<int>a;
typedef struct tree
{
    tree *l;
    tree *r;
};
tree* order(int hou[],int zhong[],int n)
{
    if(n==0)return NULL;
    tree *x=new tree;
    int i;
    for(i=0;i<n;i++)
    {
        if(hou[n-1]==zhong[i])break;
    }
    if(i==n) return NULL;
	cout<<hou[n-1]<<' ';
    x->l = order(hou,zhong,i);
	x->r = order(hou+i,zhong+i+1,n-i-1);
	
	return x;
}

int main()
{
    int n;cin>>n;
    int hou[n],zhong[n];
    for(int i=0;i<n;i++)cin>>hou[i];
    for(int i=0;i<n;i++)cin>>zhong[i];
    tree *x=order(hou,zhong,n);

    return 0;
}