#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int N, M;
int relate[505][505];
int node[505];
long long sum = 0;
int depart, desti;
bool flag = 1;

int dsearch(int from) {
	bool sign = 0;
	if (node[from])return node[from];
	for (int i = 1; i <= N; i++)
	{
		if (relate[from][i]) { node[from] += dsearch(i); sign = 1; }
	}
	if (!sign)flag = 0;
	return node[from];
}

int main() {
	cin >> N >> M;
	int temp1, temp2;
	memset(relate, 0, sizeof(relate));
	memset(node, 0, sizeof(node));
	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2;
		relate[temp1][temp2] = 1;
	}
	cin >> depart >> desti;
	node[desti] = 1;
	sum=dsearch(depart);
	cout << sum << " ";
	if (flag)cout << "Yes";
	else cout << "No";
}
