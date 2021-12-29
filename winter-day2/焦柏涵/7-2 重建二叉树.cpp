#include <bits/stdc++.h>
using namespace std;
struct btree{
	char data;
	btree *lchild,*rchild;
};
bool match(string a,string b)
{
	int numa=a.length(),numb=b.length();
	if(numa==0&&numb==0) return true;//结束条件 
	if(numa!=numb) return false;
	char c=a[numa-1];
	int site;
	for(int i=0;i<numb;i++)
	{
		if(c==b[i]) { site=i; break; }
	}
	string al=a.substr(0,site),ar=a.substr(site,numa-site-1);
	string bl=b.substr(0,site),br=b.substr(site+1);
	for(int i=0;i<al.length();i++)//不能用size 
	{
		if(bl.find(al[i])==-1) return false;
	}
	for(int i=0;i<ar.length();i++)
	{
		if(br.find(ar[i])==-1) return false;
	}
	return match(al,bl)&&match(ar,br);
}
void creat_tree(btree *&t,char *back,char *mid,int n)
{
	int num;
	char* site;
	if(n<=0)//结束条件 
	{
		t=NULL;return;
	}
	t=new btree;
	site=mid;
	while(*site!=back[n-1])
	{
		site++;
	}
	t->data=*site;
	num=site-mid;
	creat_tree(t->lchild,back,mid,num);
	creat_tree(t->rchild,back+num,mid+num+1,n-num-1);
}
void search_front(btree *t)
{
    if(t!=NULL)
    {
        cout<<t->data;
        search_front(t->lchild);
        search_front(t->rchild);
    }
}
int Depth(btree *t)
{
    int l,r;
    if(t==NULL)
        return 0;
    else
    {
        l=Depth(t->lchild);
        r=Depth(t->rchild);
        if(l>r)
            return l+1;
        else
            return r+1;
    }
}
int main()
{
	string back,mid;
	while(cin>>back>>mid)
	{
		if(match(back,mid)==false) cout<<"INVALID"<<endl;
		else
		{
			btree *t;
			//不可以直接使用string 
			//creat_tree(t,*back,*mid,back.length()); 
			char ba[26],mi[26];
			for(int i=0;i<back.length();i++) ba[i]=back[i];
			for(int i=0;i<mid.length();i++) mi[i]=mid[i];
			creat_tree(t,ba,mi,back.length());
			cout<<Depth(t)-1<<endl;//需要减1 
			search_front(t);
			cout<<endl;
		}
	}
	return 0;
}
