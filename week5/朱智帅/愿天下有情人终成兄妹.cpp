#include<iostream>
#include<string.h>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
struct person
{
	char sex;
	int fID = -1, mID = -1;
};
person P[100010];
bool vis[100010];
bool flag;
void dfs(int ID,int cnt)
{
	if (vis[ID])
	{
		flag = true;
		return;
	}
	else
	{
		vis[ID] = true;
		if (cnt == 5) return;
		if (P[ID].fID != -1)
			dfs(P[ID].fID, cnt + 1);
		if (P[ID].mID != -1)
			dfs(P[ID].mID, cnt + 1);
	}
}
int main()
{
	int n, i, m;
	int ID, motherID, fatherID;
	char sex;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> ID >> sex >> fatherID >> motherID;
		P[ID].sex = sex;
		P[ID].fID = fatherID;
		P[ID].mID = motherID;
		P[P[ID].fID].sex = 'M';
		P[P[ID].mID].sex = 'F';
	}
	cin >> m;
	int ID1, ID2;
	for (i = 0; i < m; i++)
	{
		cin >> ID1 >> ID2;
		if (P[ID1].sex == P[ID2].sex)
		{
			cout << "Never Mind" << endl;
		}
		else
		{
			memset(vis, 0, sizeof(vis));
			flag = false;
			dfs(ID1, 1);
			dfs(ID2, 1);
			if (!flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}