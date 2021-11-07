#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	void han(int n, string a, string b, string c);


	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;
	han(n, a, b, c);






	return 0;
}
void han(int n, string a, string b, string c)
{
	if (n == 1)
	{
		cout << a << "->" << c << endl;
	}
	else
	{
		han(n - 1, a, c, b);
		cout << a << "->" << c << endl;
		han(n - 1, b, a, c);
	}

}
