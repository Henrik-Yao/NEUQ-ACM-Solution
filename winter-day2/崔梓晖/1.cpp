#include <bits/stdc++.h>
using namespace std;
typedef struct nude* pnude;
typedef struct nude* btree;
typedef struct nude 
{
	int data;
	int level;
	pnude left;
	pnude right;
}nude;
int sum[105];
int num[105];
int mlevel=0;
btree build(int level) 
{
	int n;
	cin>>n;
	if (n==0)
	{
		return NULL;
	}
	btree BT=(btree)malloc(sizeof(nude));
	BT->data=n;
	BT->level=level;
	if (BT->level>mlevel)
	{
		mlevel=BT->level;
	}
	BT->left=build(level+1);
	BT->right=build(level+1);
	return BT;
}
void find(btree BT) 
{
	if (BT==NULL)
	{
		return;
    }
	if (BT->left==NULL&&BT->right==NULL) 
	{
		sum[BT->level]+=BT->data;
		num[BT->level]++;
	}
	find(BT->left);
	find(BT->right);
}
int main() 
{
	btree BT=build(0);
	find(BT);
	int maxx=-99999;
	int level=-1;
	for (int i =0;i<=mlevel;i++) 
	{
		if (sum[i]>=maxx&&num[i]!=0) 
		{
			maxx=sum[i];
			level=i;
		}
	}
	cout<<level<<endl;
	return 0;
}

