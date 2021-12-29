#include <bits/stdc++.h>
using namespace std;
 
typedef struct BTNode {
  char data;
  struct BTNode* lchild;
  struct BTNode* rchild;
} BTNode,*BiTree;

bool isValid(string s1,string s2){
    if(!s1.length()&&!s2.length()) return true;
    if(s1.length()!=s2.length()) return false;
    char root=s1[s1.length()-1];
    int k;
    for(k=0;k<s2.length();k++)
        if(root==s2[k]) break;
    string s1l=s1.substr(0,k);
    string s1r=s1.substr(k,s1.length()-1-k);
    string s2l=s2.substr(0,k);
    string s2r=s2.substr(k+1);
    for(int i=0;i<s1l.length();i++)
        if(s2l.find(s1l[i])==-1)
            return false;
    for(int i=0;i<s1r.length();i++)
        if(s2r.find(s1r[i])==-1)
            return false;
    return isValid(s1l,s2l)&&isValid(s1r,s2r);
}

void preorder(BiTree T)//ÏÈÐò±éÀú 
{
	if(T)
	{
		cout<<T->data;
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

void CreatBiTree(BiTree &T,char *post,char *in,int n){
    int num;
    char *p;
    if(n<=0){
        T=NULL;
        return;
    }
    T=(BiTree)malloc(sizeof(BTNode));
    p=in;
    while(*p!=post[n-1])
        p++;
    T->data=*p;
    num=p-in;
    CreatBiTree(T->lchild,post,in,num);
    CreatBiTree(T->rchild,post+num,in+num+1,n-num-1);
}
int GetHeight(BiTree T){
    if(T==NULL) return -1;
    else return(max(GetHeight(T->lchild),GetHeight(T->rchild)))+1;
}
string s1,s2;
int maxlevel;
int main(){
    while(cin>>s1>>s2){
      if(!isValid(s1,s2))  cout<<"INVALID"<<endl;
    else {
        	char post[30],in[30];
			for(int i=0;i<s1.length();i++)
				post[i]=s1[i];
			for(int i=0;i<s2.length();i++)
				in[i]=s2[i];
			 BiTree T;
			CreatBiTree(T,post,in,s1.length());
			cout<<GetHeight(T)<<endl;
			preorder(T);
			cout<<endl;
    }
    }
}
