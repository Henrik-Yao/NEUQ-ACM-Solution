#include<bits/stdc++.h>
using namespace std;
struct tree
{
	int da;
	tree *l,*r;
};
tree* create(int* a,int num,int n)
{
	tree* bt=new tree;
	if(a[num]==0){bt=NULL;return bt;}
	else
	{
		bt->da=a[num];
		//cout<<bt->da<<" ";
	}
	if(num*2<=n){bt->l=create(a,num*2,n);}
	else{bt->l=NULL;}
	if(num*2+1<=n){bt->r=create(a,num*2+1,n);}
	else{bt->r=NULL;}
	return bt;
}
void show1(tree* bt)
{
	if(bt!=NULL)
	{
		show1(bt->l);
		cout<<bt->da<<" ";
		show1(bt->r);
	}
}
void show2(tree* bt)
{
	if(bt!=NULL)
	{
		show2(bt->l);
		cout<<" "<<bt->da;
		show2(bt->r);
	}
}
int getde(tree* bt)
{
	if(bt==NULL){return 0;}
	else
	{
		int l=getde(bt->l);
		int r=getde(bt->r);
		return max(l+1,r+1);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		tree* bt;
		int n;
		int a[1010];
		cin>>n;
		for(int i=1;i<=n;i++){cin>>a[i];}
		bt=create(a,1,n);
		show1(bt->l);
		cout<<bt->da;
		show2(bt->r);
		cout<<endl;
		cout<<getde(bt)<<endl;
	}
	return 0;
}
