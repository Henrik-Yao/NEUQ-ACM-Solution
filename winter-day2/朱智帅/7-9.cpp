#include<iostream>
using namespace std;
typedef struct TNode
{
	int data;
	TNode* Lc, * Rc;
}*Tree;
Tree Build(int InL, int InR, int PostL, int PostR, int In[], int Post[])
{
	if (InL > InR || PostL > PostR) return NULL;
	TNode* root = (Tree)malloc(sizeof(TNode));
	int rootindex = PostR;
	root->data = Post[rootindex];
	//cout << "root:"<<root->data << endl;
	root->Lc = NULL;
	root->Rc = NULL;
	int temp = InL;
	while (In[temp] != Post[rootindex]) temp++;
	root->Lc = Build(InL, temp - 1, PostL, temp - InL + PostL - 1, In, Post);
	root->Rc = Build(temp + 1, InR, temp - InL + PostL, PostR - 1, In, Post);
	return root;
}
void Pre(Tree T)
{
	if (T)
	{
		cout << T->data << " ";
		Pre(T->Lc);
		Pre(T->Rc);
	}
}
int main()
{
	int N, In[12], Post[12], i;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> Post[i];
	}
	for (i = 0; i < N; i++)
	{
		cin >> In[i];
	}
	Tree T=Build(0, N - 1, 0, N - 1, In, Post);
	Pre(T);
	return 0;
}