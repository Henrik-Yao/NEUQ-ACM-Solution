#include<iostream>
using namespace std;

struct node{
	int data;
	node *area[100];
	node *fa;
	node(void)
	{
		data=0;
		for(int i=0; i<100; i++)	area[i]=NULL;
		fa=NULL;
		return;
	}
	~node(void)
	{
		for(int i=0; area[i]!=NULL; i++)	delete area[i];
	}
};

node* creat(int n)
{
	node *oper=new node;
	oper->data=n;
	int i=0;
	cin>>n;
	while(n)
	{
		oper->area[i]=creat(n);
		oper->area[i]->fa=oper;
		i++;
		cin>>n;
	}
	return oper;
}

bool find(node *root, int x)
{
	if(root->data==x)	return true;
	for(int i=0; root->area[i]!=NULL; i++)	if(find(root->area[i], x))	return true;
	return false;
}

node* find(int x, node *root)
{
	//cout<<"x="<<x<<" & finding data is "<<root->data<<endl;
	if(root->data==x)	return root;
	for(int i=0; root->area[i]!=NULL; i++)
	{
		node *getd=find(x, root->area[i]);
		if(getd!=NULL)	return getd;
	}
	return NULL;
}

int count(int x, int y, node *root)
{
	//cout<<"x="<<x<<" &y="<<y<<endl;
	node *fir=find(x, root);
	while(fir->fa!=NULL)
	{
		fir=fir->fa;
		if(find(fir, y))	return fir->data;
	}
	return 0;
}

int main()
{
	int T;
	cin>>T;
	for(int z=0; z<T; z++)
	{
		int fi;
		cin>>fi;
		node *root=creat(fi);
		int x, y;
		cin>>x>>x>>y;
		cout<<count(x, y, root)<<endl;
		delete root;
	}
	return 0;
}
