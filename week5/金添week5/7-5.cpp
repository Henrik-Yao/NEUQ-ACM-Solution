#include <bits/stdc++.h>
using namespace std;
int path[50010];
bool visit[50010];
bool flag;
int num;
void search(int start)
{
	if(flag)
		return;
	if (visit[start])
		return;
	if (start>=num||start<0)
		return;
	visit[start] = 1;
	if (!path[start])
	{
		flag = 1;
		return;
	}
	search(start + path[start]);
	search(start - path[start]);
}
int main()
{
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> path[i];
	}
	int start;
	cin >> start;
	search(start);
	if (flag)
		cout << "True";
	else
		cout << "False";
	return 0;
}
