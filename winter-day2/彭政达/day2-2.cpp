/*
7-2 �ؽ�������
�����ǿն��������и����кͺ�����У����д���򴴽��ö�������������߶Ⱥ��ȸ����У�
���ɾ���ö���������������и��ͺ�����в��Ϸ���������ʶ��
�����ʽ:
��������������ݣ�������10�飩��ÿ��Ϊ�����ַ�������һ�б�ʾĳ�������ĺ�����У�
�ڶ��б�ʾ���и����С�����ֵ��ΪA-Z�Ĵ�д��ĸ���ʶ�����������������26��
�ұ�֤������������ж��ǽ���ȫ���У�����һ���ǺϷ����и��ͺ�����С����뱣֤���ǿն�������
�����ʽ:
����ÿ�����ݣ������������в��Ϸ�������ͬһ�������и����кͺ�����У��������INVALID��
���������кϷ������Ϊ���У���һ��Ϊһ����������ʾ�ö������ĸ߶ȣ��ڶ���Ϊһ���ַ�����
��ʾ�ö��������ȸ����С�
��������1:
CEFDBHGA
CBEDFAGH
CBEDFAGH
CEFDBHGA
BCA 
CAB
�������1:
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
