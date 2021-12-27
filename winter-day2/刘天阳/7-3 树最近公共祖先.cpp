#include <bits/stdc++.h>
using namespace std;
vector<int>tree[1009];
//vector<int>a[109];
int Create(int n){
	int k=1;
	while(k!=0)
	{	
		cin >> k;
		if(k != 0) 
		{
			tree[n].push_back(k);
			Create(k);
		}
	}
	return 0;
}
int a, b;
int find(int n){
//	printf("我在搜索%d\n",n);
	if(n==a||n==b) return n;
	if(!tree[n].size()) return -1;
	int k[3]={-1,-1,-1}, t = 0;
	
	for (int i = 0; i < tree[n].size(); i++)
	{
		int f = find(tree[n][i]);
		if(f != -1)
		{
			k[++t] = f;
//			printf("找到了！%d\n",f);
		}
	}
	if(t == 2) return n;
	else if(t == 1) return k[t];
	else return -1;
}
int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++)
	{
		for (int j = 0; j <= 101; j++) tree[j].clear();
		int root; cin >> root;
		Create(root);
		int ling; cin >> ling;
		cin >> a >> b;
//		for (int i = 1; i <= 8; i++)
//		{
//			cout << "树木 " << i << endl;
//			for (int j = 0; j < tree[i].size(); j++) cout << "tree" << tree[i][j] << " ";
//			cout << endl;
//		}
		cout << find(root) << endl;
	}
	
	return 0;
}
