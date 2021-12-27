#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b;
int maxlevel;
struct Tree_Node
{
	char data;
	Tree_Node *le;
	Tree_Node *ri;
};
void deletree(Tree_Node *t);
void preorder(Tree_Node *T)
{
	if(T)
	{
		cout<<T->data;
		preorder(T->le);
		preorder(T->ri);
	}
}
bool pan(string a,string b) 
{
	if(a.length()==0&&b.length()==0)
		return true;
	if(a.length()!=b.length())
		return false;
	char ch=a[a.length()-1];
	int mid;
	for(int i=0;i<b.length();i++)
	{
		if(ch==b[i])
		{
			mid=i;
			break;
		}
	}
	string ale=a.substr(0,mid);
	string ari=a.substr(mid,a.length()-1-mid);
	string ble=b.substr(0,mid);
	string bri=b.substr(mid+1);
	for(int i=0;i<ale.length();i++)
	{
		if(ble.find(ale[i])==-1)
			return false;
	}
	for(int i=0;i<ari.length();i++){
		if(bri.find(ari[i])==-1)
			return false;
	}
	return pan(ale,ble)&&pan(ari,bri);
}

void createTree(Tree_Node*&t,char* back,char* middle,int n)
{
	int num;
	char* ptr;
	if(n<=0)
	{
		t=NULL;
		return;
	}
	t=new Tree_Node;
	ptr=middle;
	while(*ptr!=back[n-1])
	{
		ptr++; 
	} 
	t->data=*ptr;
	num=ptr-middle;
	createTree(t->le,back,middle,num);
	createTree(t->ri,back+num,middle+num+1,n-num-1); 
}
int get(Tree_Node*&t)
{
	int l,r;
	if(t==NULL)
		return 0;
	else{
		l=get(t->le);
		r=get(t->ri);
		if(l>r)
		return l+1;
		else return r+1;
	}
}

int main()
{
	while(cin>>a>>b)
	{
		if(!pan(a,b))
		cout<<"INVALID"<<endl;
		else{
			char back[30],middle[30];
			for(int i=0;i<a.length();i++)
				back[i]=a[i];
			for(int i=0;i<b.length();i++)
				middle[i]=b[i];
			Tree_Node *T;
			createTree(T,back,middle,a.length());
			cout<<get(T)-1<<endl;
			preorder(T);
			cout<<endl;
		
		}
	}
	return 0;
}
void deletree(Tree_Node *t){
	if(t==NULL)
		return;
	deletree(t->le);
	deletree(t->ri);
}
