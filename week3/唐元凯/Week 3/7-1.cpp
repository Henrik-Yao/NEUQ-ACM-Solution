#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
bool flag = 0, safe[105];
int m, n, k;
int depart, desti;

void fsearch(int from, int to,int road[105][105]) {
	if (flag)return;
	for (int i = 0; i < m; i++)
	{
		if (safe[i] && road[from][i]&& (i != from)) {
			if (i == desti) { flag = 1; return; }
			road[from][i] = 0;
			road[i][from] = 0;
			fsearch(i, desti,road);
			if (flag)return;
		}
	}
}

int main()
{
	cin >> m >> n >> k;
	int temp;
	memset(safe, 0, sizeof(safe));
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		safe[temp] = 1;
	}
	int temp1, temp2;
	int road[105][105];
	memset(road, 0, sizeof(road));
	for (int i = 0; i < k; i++)
	{
		cin >> temp1 >> temp2;
		road[temp1][temp2] = 1;
		road[temp2][temp1] = 1;
	}
	cin >> depart >> desti;
	if (!safe[desti])printf("The city %d is not safe!", desti);
	else {
		fsearch(depart, desti,road);
		if (flag == 1)printf("The city %d can arrive safely!", desti);
		else printf("The city %d can not arrive safely!", desti);
	}
}
