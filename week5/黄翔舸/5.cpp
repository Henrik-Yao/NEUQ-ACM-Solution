#include<iostream>
using namespace std;
bool bj;
int m[50001], rk, length, jud[50001];
void end(int rk);
int main()
{

	cin >> length;
	for (int i = 0; i < length; i++) cin >> m[i];
	cin >> rk;
	end(rk);
	if (bj) cout << "True";
	else cout << "False";
	return 0;
}
void end(int rk)
{
	jud[rk] = 1;
	if (m[rk] == 0)
	{
		bj = 1;
		return;
	}
	if ((jud[rk + m[rk]] || rk + m[rk] >= length) && (jud[rk - m[rk]] || rk - m[rk] < 0)) return;
	if (rk + m[rk] < length)
		end(rk + m[rk]);
	if (rk - m[rk] >= 0)
		end(rk - m[rk]);

}