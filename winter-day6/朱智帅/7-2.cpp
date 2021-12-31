#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct P
{
	string name;
	int data;
};
bool cmp(P p1, P p2)
{

	if (p1.data < p2.data) return true;
	else
	{
		if (p1.data == p2.data)
		{
			return p1.name > p2.name;
		}
		else return false;
	}
}
int main()
{
	int n;
	cin >> n;
	P p[100010];
	int i;
	for (i = 0; i < n; i++) cin >> p[i].name >> p[i].data;
	sort(p, p + n, cmp);
	for (i = n - 1; i > -1; i--)
	{
		cout << p[i].name << " " << p[i].data << endl;
	}
}
