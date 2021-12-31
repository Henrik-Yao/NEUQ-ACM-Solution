/*
7-7 �������������
��������������й���һ�ö����������н�����������10������
ͨ���öӼ�¼�����ʴ���ķ���ʵ�ֶԶ��������а��������
����������С����ͬ���������������������С�
�����ʽ:
��һ������Ԫ�ظ���
�ڶ��������������У��Կո����
�����������������У��Կո����
�����ʽ:
����˶������İ���������У��Կո���������Ҳ��һ���ո�
��������:
5
10 20 40 30 50
20 40 10 50 30
�������:
10 20 30 40 50 
*/
#include <bits/stdc++.h>
using namespace std; 
typedef struct node{
    int value;
    struct node *left,*right;
}*tree;
int get(int *front,int *middle, int n){
    int i,ch;
    for(i=0,ch=front[0];i<n;i++)
        if(middle[i]==ch) return i;
    return -1;
}
tree build(int *front,int *middle,int n){
    if(n==0) return NULL;
    int val=front[0];
    int i=get(front,middle, n);
    node *r=(tree)malloc(sizeof(node));
    r->value=root_val; 
    r->left=build(front+1,middle,i);
    r->right=build(front+i+1,middle+i+1,n-i-1);
    return r;
}
void postorder(tree root){  
    tree pt;
    queue<tree> q;
    if(root==NULL) return ;
    q.push(root);
    while(!q.empty() && q.front()){
    	cout<<q.front()->value<<" ";
    	if(q.front()->left!=NULL) q.push(q.front()->left);
    	if(q.front()->right!=NULL) q.push(q.front()->right);
    	q.pop();
	}
}
int main(){
	int a[15],b[15],n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
    node *root=build(a,b,n);
    postorder(root);
    cout<<endl;
}
