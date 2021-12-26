#include<iostream>
#include<cstring>
using namespace std;

string mid;
string aft;

bool fit=true;
int deep=0;

struct node{
	string data;
	node *left;
	node *righ;
	node(void)
	{
		left=NULL;
		righ=NULL;
	}
	~node(void)
	{
		if(left!=NULL)	delete left;
		if(righ!=NULL)	delete righ;
	}
};

node* creat(int f_m, int l_m, int f_a, int l_a, int deepth)
{
	if(fit);
	else	return NULL;
	
	if(f_m>l_m)	return NULL;
	if(f_a>l_a)	return NULL;
	
	/*
	cout<<"now the aft is ";
	for(int i=f_a; i<=l_a; i++)	cout<<aft[i];
	cout<<endl;
	cout<<"now the mid is ";
	for(int i=f_m; i<=l_m; i++)	cout<<mid[i];
	cout<<endl;
	*/
	
	if(f_m==l_m)
	if(mid[f_m]==aft[f_a])
	{
		if(deepth>deep)
		{
			deep=deepth;
			//cout<<"deep up to "<<deep<<" when is "<<mid[f_m]<<endl;
		}
		
		node *root=new node;
		root->data+=mid[f_m];
		return root;
	}
	else
	{
		fit=false;
		return NULL;
	}
	else;
	if(f_a==l_a)
	if(mid[f_m]==aft[f_a])
	{
		if(deepth>deep)
		{
			deep=deepth;
			//cout<<"deep up to "<<deep<<" when is "<<aft[f_a]<<endl;
		}
		
		node *root=new node;
		root->data+=aft[f_a];
		return root;
	}
	else
	{
		fit=false;
		return NULL;
	}
	else;
	
	node *root=new node;
	int ro;
	for(ro=f_m; ro<=l_m; ro++)
	if(mid[ro]==aft[l_a])	break;
	if(ro>l_m)
	{
		fit=false;
		return NULL;
	}
	root->data+=mid[ro];
	
	if(deepth>deep)
	{
		deep=deepth;
		//cout<<"deep up to "<<deep<<" when is "<<mid[ro]<<endl;
	}
	
	int lon_left=ro-f_m;
	int lon_righ=l_m-ro;
	
	root->left=creat(f_m, ro-1, f_a, f_a+lon_left-1, deepth+1);
	root->righ=creat(ro+1, l_m, l_a-lon_righ, l_a-1, deepth+1);
	return root;
}

void pre(node *root)
{
	cout<<root->data;
	if(root->left!=NULL)	pre(root->left);
	if(root->righ!=NULL)	pre(root->righ);
	return;
}

/*
string stru_mid(node *root)
{
	string temp;
	if(root->left!=NULL)	temp+=stru_mid(root->left);
	temp+=root->data;
	if(root->righ!=NULL)	temp+=stru_mid(root->righ);
	return temp;
}

string stru_aft(node *root)
{
	string temp;
	if(root->left!=NULL)	temp+=stru_aft(root->left);
	if(root->righ!=NULL)	temp+=stru_aft(root->righ);
	temp+=root->data;
	return temp;
}
*/

int main()
{
	string temp;
	while(getline(cin, temp))
	{
		int n=0;
		for(int i=0; temp[i]!='\0'; i++)
		{
			aft+=temp[i];
			n+=1;
		}
		temp.clear();
		getline(cin, temp);
		for(int i=0; i<n; i++)	mid+=temp[i];
		if(n)
		{
			node *root=creat(0, n-1, 0, n-1, 1);
			
			/*
			if(mid==stru_mid(root));
			else	fit=false;
			if(aft==stru_aft(root));
			else	fit=false;
			*/
			
			if(fit)
			{
				cout<<deep-1<<endl;
				pre(root);
				cout<<endl;
			}
			else	cout<<"INVALID"<<endl;
			delete root;
		}
		temp.clear();
		fit=true;
		deep=0;
		aft.clear();
		mid.clear();
	}
	return 0;
}
