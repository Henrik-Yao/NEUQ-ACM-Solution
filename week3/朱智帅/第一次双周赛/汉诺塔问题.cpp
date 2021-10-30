#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<string.h>
using namespace std;
int N;
char a[3][20];
void Han(int n, int s, int e)
{
	if (n == 1)
	{
		cout << a[s] << "->" << a[e] << endl;
		return;
	}
	Han(n - 1, s, 3 - s - e);
	cout << a[s] << "->" << a[e] << endl;
	Han(n - 1, 3 - s - e, e);
}
int main()
{
	cin >> N;
	cin >> a[0] >> a[1] >> a[2];
	Han(N, 0, 2);
	return 0;
}