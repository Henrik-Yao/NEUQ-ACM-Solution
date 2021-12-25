#include<iostream>
using namespace std;
int visited[1005] = { 0 };
int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	int i, now = 0;
	for (i = 0; i < N; i++)
	{
		int step = 1;
		if (i % 2 == 0)
		{
			for (; step < M;)
			{
				now = (now + N - 1) % N;
				if (!visited[now])
					step++;
			}
			visited[now] = 1;
			cout << now + 1 << " ";
		}
		else
		{
			for (; step < K;)
			{
				now = (now + 1) % N;
				if (!visited[now])
					step++;
			}
			visited[now] = 1;
			cout << now + 1 << " ";
		}
	}
	return 0;
}