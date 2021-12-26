#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const int maxv = 100 + 10;
int pre_order[maxv], lch[maxv], rch[maxv],sum[maxv];
int n;

bool read_list(int *a) {
	n = 0;
	while(cin >> a[n++]){};
	return n > 0;
}

int build(int l, int floor) {
	static int L = l;
	if (pre_order[L] == 0)return 0;
	int root = pre_order[L];
	sum[floor] += build(++L, floor + 1);//模拟左子树
	sum[floor] += build(++L, floor + 1);//模拟右子树
	return root;
}

int main() {
	read_list(pre_order);
	sum[0] = pre_order[0];
	build(0, 1);
	int pos = 0;
	for (int i = 0; i < maxv; i++)
	{
		if (abs(sum[i]) >= abs(sum[pos]))pos = i;
	}
	cout << pos;
}