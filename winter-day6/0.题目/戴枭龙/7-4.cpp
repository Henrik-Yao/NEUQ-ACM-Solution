#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, a[maxn], r[maxn];
long long ans = 0;

void mergesort(int s, int e) {
	int i, j, k, m;
	if (s == e)
		return;
	m = (s + e) / 2; //ȡ�е�
	mergesort(s, m); //�ݹ�������
	mergesort(m + 1, e); //�ݹ�������
	i = s, j = m + 1, k = s;
	while (i <= m && j <= e) { //��·�鲢�����򣩹���
		if (a[i] <= a[j]) {
			r[k] = a[i];
			i++;
			k++;
		} else {
			r[k] = a[j];
			j++;
			k++;
			ans += m - i + 1;
		}
	} //��������ʣ���Ԫ�ؽ���r����
	while (i <= m) {
		r[k] = a[i];
		i++;
		k++;
	}
	while (j <= e) {
		r[k] = a[j];
		j++;
		k++;
	}
	for (int i = s; i <= e; i++)
		a[i] = r[i]; //���鸳��
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	mergesort(1, n);
	cout << ans << endl;
	return 0;
}