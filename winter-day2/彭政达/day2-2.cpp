/*
7-2 重建二叉树
给定非空二叉树的中根序列和后根序列，请编写程序创建该二叉树，计算其高度和先根序列，
最后删除该二叉树；如给定的中根和后根序列不合法，则亦能识别。
输入格式:
输入包含多组数据（不超过10组），每组为两行字符串，第一行表示某二叉树的后根序列，
第二行表示其中根序列。结点的值均为A-Z的大写字母，故二叉树结点个数不超过26，
且保证输入的两个序列都是结点的全排列，但不一定是合法的中根和后根序列。输入保证不是空二叉树。
输出格式:
对于每组数据，如果输入的序列不合法（不是同一棵树的中根序列和后根序列），则输出INVALID；
若输入序列合法，输出为两行，第一行为一个整数，表示该二叉树的高度，第二行为一个字符串，
表示该二叉树的先根序列。
输入样例1:
CEFDBHGA
CBEDFAGH
CBEDFAGH
CEFDBHGA
BCA 
CAB
输出样例1:
3
ABCDEFGH
INVALID
INVALID
*/
#include <bits/stdc++.h>
using namespace std;
vector<char> v;
int flag=1;
typedef struct node{
  char data;
  struct node* lchild,* rchild; 
}*tree;
tree postorder(char post[],char mid[],int len){
	if(!len) return NULL;
  	tree t=(tree)malloc(sizeof(node));
  	t->data=post[len-1];
  	int i=0;
  	for(i=0;i<len;i++)
    	if(post[len-1]==mid[i]) break;
  	if(i==len){
    	flag=0;
    	return NULL;
  	}
  	else{
    	v.push_back(t->data);
    	t->lchild=postorder(post,mid,i);
    	t->rchild=postorder(post+i,mid+i+1,len-i-1);
  	}
  	return t;
}
int getheight(tree t){
	if(t==NULL) return 0;
  	int l=getheight(t->lchild);
  	int r=getheight(t->rchild);
  	return 1+(l>r?l:r);
}
int main(){
  	string s,t;
  	while(cin>>s>>t){
  		flag=1;fir.clear();
  		char post[s.size()],mid[s.size()];
  		for(int i=0;i<s.size();i++){
		  	post[i]=s[i];
  			mid[i]=t[i];
  		}
  		tree tr=postorder(post,mid,s.size());
  		if(flag){
    		cout<<getheight(tr)-1<<endl;
    		for(int i=0;i<v.size();i++) cout<<v[i];
  		}
		else cout<<"INVALID"<<endl;
	}
}
