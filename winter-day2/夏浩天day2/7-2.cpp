#include<iostream>
using namespace std;
typedef struct tree
{
	tree* lc;
	tree* rc;
};
string fir = "";
bool istree;
tree* postorder(char post[], char mid[], int n)
{
	if (n == 0) return NULL;
	tree* bt = new tree;
	int i;
	for (i = 0; i < n; i++)
		if (post[n - 1] == mid[i]) break;
	if (i == n)
	{
		istree = 0;
		return NULL;
	}
	fir += post[n - 1];
	bt->lc = postorder(post, mid, i);
	bt->rc = postorder(post + i, mid + i + 1, n - i - 1);
	return bt;
}
int getheight(tree* bt)
{
	if (!bt) return 0;
	return max(getheight(bt->lc), getheight(bt->rc)) + 1;
}
int main()
{
	string s1,s2;
	while (cin >> s1 >> s2)
	{
		istree = 1;
		int n = s1.size();
		char post[10001], mid[10001];
		for (int i = 0; i < n; i++) 	post[i] = s1[i];
		for (int i = 0; i < n; i++)     mid[i] = s2[i];
		tree* bt = postorder(post, mid, n);

		if (istree)
		{
			cout << getheight(bt) - 1 << endl;
			cout << fir;
		}
		else cout << "INVALID";
		cout << endl;
		fir = "";
	}
	return 0;
}