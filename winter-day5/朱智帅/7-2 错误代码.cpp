#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
struct Node
{
	string wordanme;
	uint data;
};
Node N[10001];
bool cmp(Node N1, Node N2)
{
	return N1.data < N2.data;
}
int m, n, k;
set<string>S;
map<string, uint>M;
int main()
{
	int i;
	uint count;
	string words;
	cin >> n >> m >> k;
	for (i = 0; i < n; i++)
	{
		cin >> count >> words;
		S.insert(words);
		if (M[words] < count) M[words] = count;
	}
	for (i = 0; i < m; i++)
	{
        memset(N,0,sizeof(N));
		cin >> words;
		int K = 0, len = words.size();
		for (auto it = S.begin(); it != S.end(); ++it)
		{
			if (words == (*it).substr(0, len))
			{
				if ((*it) != words)
				{
					N[K].wordanme = (*it);
					N[K].data = M[*it];
					K++;
				}
			}
		}
		int l, j;
		if (K == 0)
		{
			cout << "no suggestion" << endl << endl;
			continue;
		}
		uint max, oldmax = INT32_MAX, maxtag = 0;
		sort(N, N + K, cmp);
		for (j = K - 1; j > K - k - 1; j--)
		{
			cout << N[j].wordanme << endl;
		}
		if (i + 1 < m)cout << endl;
	}
	return 0;
}