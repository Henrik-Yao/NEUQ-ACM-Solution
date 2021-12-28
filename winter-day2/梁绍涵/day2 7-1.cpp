#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	struct tree *left,*right;
	int data,level;
}*bitree,node;
int max1=-1000,ans1,max2=-100;
int ans[100],num[100];
bitree creat(int floor)
{
	bitree T;
	int x;
	cin>>x;
	if(x!=0)
	{
		T=new node;
		T->data=x;
		T->level=floor;
		max1=max(floor,max1);
		T->left=creat(floor+1);
		T->right=creat(floor+1);
	}
	else
	{
		T=new node;
		T->data=0;
	}
	return T;
}
void findmax(bitree &T)
{
	if(T->data==0)
	return;
	if(T->left->data==0&&T->right->data==0)
	{
		ans[T->level]+=(T->data);
		num[T->level]++;
	}
	findmax(T->left);
	findmax(T->right);
	return;
}
int main()
{
	int n;
	bitree T;
	T=creat(1);
	findmax(T);
//	cout<<max1;
	for(int i=1;i<=max1;i++)
	{
//		cout<<i<<":"<<num[i]<<" "<<endl;
		if(ans[i]>=max2&&num[i]!=0)
		{
			max2=ans[i];
			ans1=i;
		}
	}
	cout<<ans1-1;
} 
