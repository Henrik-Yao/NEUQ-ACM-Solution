#include <bits/stdc++.h>
using namespace std;

void hannuota(int n, string A, string B, string C) {
	if (n == 1) {
		cout << A << "->" << C << endl;//第二步 将最后一个盘子从A移动到C
	} else {
		hannuota(n - 1, A, C, B);//第一步 将n-1个盘子从A移动到B
		cout << A << "->" << C << endl;
		hannuota(n - 1, B, A, C);//第三步 将n-1个盘子从B移动到C
	}
}

int main() {
	int n;
	string  a1, b1, c1;
	cin >> n >> a1 >> b1 >> c1;
	hannuota(n, a1, b1, c1);
	return 0;
}