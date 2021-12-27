#include<iostream>
#include<string>
#include<stack>
using namespace std;
int N, i, a, b, c;
stack<int>S;
int pre[1000005];
int stk[1000005];
int main()
{
	cin >> N;
	while (N--)
	{
		int  n = 0;
		cin >> c;
		S.push(c);
		while (!S.empty())
		{
			cin >> c;
			if (c)
			{
				pre[c] = S.top();
				stk[c] = n++;
				S.push(c);
			}
			else
			{
				S.pop();
				n--;
			}
		}
		cin >> c;
		cin >> a >> b;
		int t;
		if (stk[a] > stk[b])
		{
			t = stk[a] - stk[b];
			while (t--)
			{
				a = pre[a];
			}
		}
		else {
			t = stk[b] - stk[a];
			while (t--) {
				b = pre[b];
			}
		}
		while (pre[a] != pre[b]) {
			a = pre[a];
			b = pre[b];
		}
		cout << pre[a] << endl;
	}
	return 0;
}