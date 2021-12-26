#include<iostream>
using namespace std;
typedef struct
{
	int64_t Left, Right;
	int64_t sum;
}Tree;
Tree T[4000040];
int64_t number[1000010];
void Build(int64_t root, int64_t Left, int64_t Right)
{
	if (Left == Right) T[root] = { Left, Right, number[Right] };
	else
	{
		T[root] = { Left,Right };
		int64_t mid = (Left + Right) / 2;
		Build(root * 2, Left, mid);
		Build(root * 2 + 1, mid + 1, Right);
		T[root].sum = T[2 * root].sum + T[2 * root + 1].sum;
	}
}
int64_t Query(int64_t root, int64_t Left, int64_t Right)
{
	if (T[root].Left >= Left && T[root].Right <= Right) return T[root].sum;
	int64_t mid = (T[root].Left + T[root].Right) / 2;
	int64_t sum = 0;
	if (Left <= mid) sum = Query(2 * root, Left, Right);
	if (Right > mid) sum += Query(2 * root + 1, Left, Right);
	return sum;
}
void Modify(int64_t root, int64_t x, int64_t v)
{
	if (T[root].Left == T[root].Right) T[root].sum += v;
	else
	{
		int64_t mid = (T[root].Left + T[root].Right) / 2;
		if (x <= mid) Modify(root * 2, x, v);
		else Modify(root * 2 + 1, x, v);
		T[root].sum = T[2 * root].sum + T[2 * root + 1].sum;
	}
}
int main()
{
	int64_t n, q, i, num, j;
	cin >> n >> q;
	for (i = 1; i <= n; i++) cin >> number[i];
	Build(1, 1, n);
	for (i = 0; i < q; i++)
	{
		int64_t k, a, b;
		cin >> k >> a >> b;
		if (k == 2) cout << Query(1, a, b) << endl;
		else Modify(1, a, b);
		//cout << endl;
		//for (j = 1; j <= n; j++) cout << Query(1,j,j) << " ";
		//cout << endl;
	}
	return 0;
}