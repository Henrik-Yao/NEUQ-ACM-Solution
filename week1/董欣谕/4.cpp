#include <bits/stdc++.h>
using namespace std;
int n,step=1;
bool check(int n,int a) {
	if (n%a==0) return 1;
	else return 0;
}
void dfs(int x) {
	if (x==1)
		return;
	for (int i=1; i<x; i++)
		if (check(x,i)) step++,dfs(i);
}
int main() {
	cin>>n;
	dfs(n);
	cout<<step;
	return 0;
}
