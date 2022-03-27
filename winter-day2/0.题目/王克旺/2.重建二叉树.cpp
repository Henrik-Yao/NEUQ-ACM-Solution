#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    char data;
    Node *left;
	Node *right;
}Node,*Tree;
bool judge(string m,string b)
{  
    if(m.length()==0&&b.length()==0)
    {
    	return true;
	}    
	if(m.length()!=b.length())
    {
    	return false;
	}
	int i;
    char ch=m[m.length()-1];
    for(i=0;i<b.length();i++)
	{
        if(ch==b[i])
        {
        	break;
		}     
    }
    string mleft=m.substr(0,i);
    string mright=m.substr(i,m.length()-1- i);
    string bleft=b.substr(0,i);
    string bright=b.substr(i+1);
    for(i=0;i<mleft.length();i++)
	{
        if(bleft.find(mleft[i])==-1)
        {
        	return false;
		}      
    }
    for(i=0;i<mright.length();i++)
	{
        if(bright.find(mright[i])==-1)
        { 
        	return false;
		}          
    }
    return judge(mleft,bleft)&&judge(mright,bright);
}
Tree create(char *post,char *in,int n)
{
    if(n<1)
    {
    	return NULL;
	}    
    Tree tree=(Tree)malloc(sizeof(Node));
    tree->data=post[n-1];
    int i;
    for(i=0;i<n;i++)
	{
        if(post[n-1]==in[i])
        {
        	break;
		}         
    }
    tree->left=create(post,in,i);
    tree->right=create(post+i,in+i+1,n-i-1);
    return tree;
}
int height(Tree tree)
{
    if(!tree)
    {
    	return 0;
	}  
	int left,right;
	left=height(tree->left);
    right=height(tree->right);
    if(left>=right)
    {
    	return left+1;
	}
	else
	{
		return right+1;
	}
}
void pre(Tree tree)
{
    if(!tree)
    {
    	return;
	} 
    cout<<tree->data;
    pre(tree->left);
    pre(tree->right);
}
int main()
{
    string m,b;
	while(cin>>m>>b)
	{	
        if(!judge(m,b))
        {
        	cout<<"INVALID"<<endl;
    	}     
        else
    	{
            int l=m.length();
            char post[26],in[26];
            int p=0;
            for(int i=0;i<l;i++)
            {
            	post[p++]=m[i];
    		}       
            p=0;
            for(int i=0;i<l;i++)
            {
            	in[p++]=b[i];
	    	}   
            Tree tree=create(post,in,l);
            cout<<height(tree)-1<<endl;
            pre(tree);
            cout<<endl;
        }
	}
    return 0;
}
