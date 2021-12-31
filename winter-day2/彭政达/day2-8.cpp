/*
7-8 �������������
����ȫ�������Ĳ�α�������һ�ö������ı������У�������0��ʾ���㣩��
Ҫ������ö���������ȼ���������ö������õ������С�
�����ʽ:
��������һ������T����ʾ�������ݵ�������Ȼ����T��������ݡ�
ÿ�����������������һ��������n��n��1000������������Ķ������Ľ������
����Ȼ�����п��ܰ������㣩������ž�Ϊ������,�Ҹ�����ͬ�� 
Ȼ������n������������ʾ����ȫ������������1��1����㣬��2��2������3��4������4����8��������
�Ĳ�α��������Ķ������������У����ĳ����㲻���ڣ����㣩������0���档
�����ʽ:
����ÿ����ԣ���һ�������������������õ������У�ÿ��������֮����һ���ո񣩣�
�ڶ����������������ȡ�
��������:
2
1 1
4 1 4 0 2
�������:
1
1
2 4 1
3
*/
#include <bits/stdc++.h>
using namespace std;
int s=0;
typedef struct node{
    int value;
    node *left,*right;
}*tree;
tree createnode(){
    node *n=new node;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void cr(tree &root, int numbers[], int len){
    if(len==0) return;
    else{
        queue<tree> q;
        int i=0;
        root=createNode();
        root->value=numbers[i++];
        q.push(root);
        while(!q.empty()){
            tree temp=q.front();
            q.pop();
            if(i<len){s++;
                if(numbers[i]!=0){
                    temp->left=createNode();
                    temp->left->value=numbers[i];
                    q.push(temp->left);
                }
                i++;
            }
            if(i<len){
                if(numbers[i]!=0){s++;
                    temp->right=createNode();
                    temp->right->value=numbers[i];
                    q.push(temp->right);
                }
                i++;
            }
        }
    }
}
void preOrder(tree root){
    if(root){
        preOrder(root->left);
        if(root->value) cout<<root->value;
        if(s--) cout<<" ";
        preOrder(root->right);
    }
}
int getheight(tree root){
	if(root){
		int r=getheight(root->right);
		int l=getheight(root->left);
		return 1+(r>l?r:l);
	}
	else return 0;
}
int main(){
    int t;
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
    	s=0;
    	int num[1005],len;
    	cin>>len;
    	for(int i=0;i<len;i++) cin>>num[i];
    	tree r=NULL;
    	cr(r,num,len);
    	preOrder(r);
    	cout<<endl<<getheight(r)<<endl;
    }
}

