#include<iostream>
#include<string.h>
using namespace std;
int hlt(int n, string a, string b, string c)
{
	if (n == 1)
	{
		cout << a << "->" << c<<endl;
		return 0;
	}
	else
	{
		hlt(n - 1, a, c, b);
		hlt(1, a, b, c);
		hlt(n - 1, b, a, c);
	}

}
int main()
{
	int n;
	string a, b, c;
	cin >> n>>a>>b>>c;
	hlt(n, a, b, c);
}