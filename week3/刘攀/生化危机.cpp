#include<bits/stdc++.h>
using namespace std;
bool flag = 0, safe[100];
int m, n, k;
int road[101][101];
int start, l;
void f(int from, int to) {
	if (flag)return;
	for (int i = 0; i < m; i++)
	{
		if (safe[i] && road[from][i] && (i != from)) {
			if (i == l) {
				flag = 1;
			}
			else {
				f(i, l);
			}
			road[from][i] = 0;
			road[i][from] = 0;
		}
	}
}

int main()
{
	cin >> m >> n >> k;
	int t;
	memset(safe, 0, sizeof(safe));
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		safe[t] = 1;
	}
	int t1, t2;
	memset(road, 0, sizeof(road));
	for (int i = 0; i < k; i++)
	{
		cin >> t1 >> t2;
		road[t1][t2] = 1;
		road[t2][t1] = 1;
	}
	cin >> start >> l;
	if (!safe[l])printf("The city %d is not safe!", l);
	else {
		f(start, l);
		if (flag == 1)printf("The city %d can arrive safely!", l);
		else printf("The city %d can not arrive safely!", l);
	}
}

