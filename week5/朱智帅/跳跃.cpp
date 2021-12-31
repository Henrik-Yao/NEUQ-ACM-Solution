#include<iostream>
#include<queue>
using namespace std;
int n, star;
int step[10001], visit[10001] = { 0 };
void bfs()
{
	queue<int> Q;
	Q.push(star);
	while (Q.size())
	{
		int nowplace = Q.front();
		Q.pop();
		if (step[nowplace] == 0)
		{
			cout << "True" << endl;
			return;
		}
		else
		{
			visit[nowplace] = 1;
			if (!visit[nowplace + step[nowplace]]&&nowplace+step[nowplace]<n)
			{
				visit[nowplace+step[nowplace]] = 1;
				Q.push(nowplace + step[nowplace]);
			}
			if (!visit[nowplace - step[nowplace]] && nowplace - step[nowplace] > -1)
			{
				visit[nowplace-step[nowplace]] = 1;
				Q.push(nowplace - step[nowplace]);
			}
		}
	}
    cout<<"False"<<endl;
}
int main()
{
	int i;
	cin >> n;
	for (i = 0; i < 10000; i++)
	{
		step[i] = -1;
	}
	for (i = 0; i < n; i++)
	{
		cin >> step[i];
	}
	cin >> star;
	bfs();
	return 0;
}