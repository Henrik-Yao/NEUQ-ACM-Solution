#include<bits/stdc++.h>
using namespace std;
int n,pre[11],in[11];
struct tree
{
	int da;
	tree* l;
	tree* r;
}trees;
tree* create(int pren,int inn,int n)
{
	if(n<=0){return NULL;}
	tree* bt=(tree*)malloc(sizeof(trees));
	bt->da=pre[pren];
	int i;
	for(i=inn;i<inn+n;i++)
	{
		if(in[i]==pre[pren]){break;}
	}
	int k=i-inn;
	//cout<<n<<" ";
	bt->l=create(pren+1,inn,k);
	bt->r=create(pren+1+k,i+1,n-k-1);
	return bt;
}
void show(tree* b)
{
	if(b!=NULL)
	{
		show(b->l);
		show(b->r);
		cout<<b->da<<" ";
	}
}
int main()
{
	tree* bt=NULL;

	cin>>n;
	for(int i=0;i<n;i++){cin>>pre[i];}
	for(int i=0;i<n;i++){cin>>in[i];}
	bt=create(0,0,n);
	//cout<<endl;
	show(bt);
	return 0;
}
