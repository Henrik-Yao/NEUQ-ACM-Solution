#include <bits/stdc++.h>
using namespace std;
bool ju = 1;
struct Node{
	Node *l, *r;
	char val;
	Node(){
		l = r = NULL;
	}
};
int find(char *a, char c,int n){
	for (int i = 0; i < n; i++){
		if(c == a[i]){
			return i;
		}
	}
	return -1;
}
Node* BuildTree(int n, char *a, char *b)  //aΪ���� bΪ����
{
	if(n<=0 || ju==0) return NULL;  //ע���п���nС��0�����Բ�Ҫʹ��if��!n) 
	Node *x;
	x = new Node;
	x->val = b[n-1];   //��Ϊ�������һ��
	int t = find(a, b[n-1],n); //���������ҵ�����λ��  ���ҷֱ�Ϊ��������
	if(t == -1) {
		ju = 0;
		return NULL;
	}
	x->l = BuildTree(t, a, b);  //��Ϊ��ʼΪ0����t��λ�ü�Ϊ����
	x->r = BuildTree(n-t-1, a+t+1,b+t); //������������t���͸���1��ȥ����������������ȥ����t�������Ļ��������棬��n����
	return x;                  
} 
int ans = 0;
void qian(Node *root,int t){
	if(root == NULL) return;
	cout << root->val;
	qian(root->l, t+1);
	qian(root->r, t+1);
}
void anss(Node *root,int t){
	if(root == NULL) return;
	if(t > ans) ans = t;
	anss(root->l, t+1);
	anss(root->r, t+1);
}
int main()
{
	char a[110], b[110];
    while(~scanf("%s%s", b, a)){
    	ju = 1;
        Node *root = BuildTree(strlen(b), a, b);
        if(ju){
        	anss(root, 0);
    	    cout << ans << endl;
    	    qian(root, 1);cout << endl;
		}
		else cout << "INVALID" << endl;
    }
	return 0;
}
