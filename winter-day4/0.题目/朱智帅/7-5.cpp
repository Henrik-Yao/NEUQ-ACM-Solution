#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
int Map[105][105];
int visited[105][105] = { 0 };
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
struct node
{
	int x, y;
};
struct Node
{
	int x, y, cost;
	vector<node>so;
};
int m, n;
Node Start, End;
queue<Node>Q;
bool isok(Node N)
{
	if (Map[N.x][N.y] != -1) return true;
	else return false;
}
void BFS()
{
	int i, min = INT16_MAX;
	Node MinNode;
	Q.push(Start);
	while (!Q.empty())
	{
		Node temp = Q.front(), newtemp;
		Q.pop();
		if (temp.x == End.x && temp.y == End.y)
		{
			if (min > temp.cost) min = temp.cost;
			MinNode = temp;
			continue;
		}
		for (i = 0; i < 4; i++)
		{
			newtemp.x = temp.x + pos[i][0];
			newtemp.y = temp.y + pos[i][1];
			if (isok(newtemp))
			{
				newtemp.cost = Map[temp.x][temp.y] + temp.cost;
				if (visited[newtemp.x][newtemp.y])
				{
					if (visited[newtemp.x][newtemp.y] > newtemp.cost) visited[newtemp.x][newtemp.y] = newtemp.cost;
					else continue;
				}
				else visited[newtemp.x][newtemp.y] = newtemp.cost;
				newtemp.so.assign(temp.so.begin(), temp.so.end());
				newtemp.so.push_back({ temp.x,temp.y });
				Q.push(newtemp);
			}
		}
		
	}
	cout << "(" << End.x << " " << End.y << ")";
	while (!MinNode.so.empty())
	{
		cout << "(" << MinNode.so.back().x << " " << MinNode.so.back().y << ")";
		MinNode.so.pop_back();
	}
}
int main()
{
	int i, j, k;
	cin >> m >> n >> Start.x >> Start.y >> End.x >> End.y;
	Start.cost = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
	}
	BFS();
}