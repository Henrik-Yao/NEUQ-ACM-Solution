/*
7-9 ����������������
����ĿҪ���ú������к��������й���һ�ö����������н�����������10��������������������С�
�����ʽ:
�ڵ�һ��������Ԫ�ظ�����
�ڶ���������������У��ÿո�ָ���
�������������������У��ÿո�ָ���
�����ʽ:
����˶��������������У��ÿո�ָ������Ҳ��һ���ո�
��������:
5
20 40 50 30 10
20 10 40 30 50
�������:
10 20 30 40 50 
      10                    
  20    30                      
      40  50                   
*/
#include <bits/stdc++.h>
using namespace std; 
typedef struct node{
    int value;
    struct node *left,*right;
}*tree;
void cr(tree& t, int* back, int* middle, int n){
    int num;
    int* ptr;
    if (n<=0){
        t=NULL;
        return;
    }
    t=new node;
    ptr=middle;
    while (*ptr != back[n - 1]) ptr++;
    t->value= *ptr;
    num=ptr-middle;
    cr(t->left,back,middle,num);
    cr(t->right,back+num,middle+num+1,n-num -1);
}
void postorder(tree root){  
    if(root!=NULL){
    	cout<<root->value<<" ";
    	postorder(root->left);
    	postorder(root->right);
	}
}
int main(){
	int a[15],b[15],n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
    tree root;
	cr(root,a,b,n);
    postorder(root);
    cout<<endl;
}
