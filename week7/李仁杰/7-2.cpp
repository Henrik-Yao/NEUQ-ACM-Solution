#include<iostream>
using namespace std;

string f()
{
	char c;
	string ans = "";
	while (cin >> c)
	{
		if (c == '[')
		{
            string copy;
            int times;
			cin >> times;
			copy = f();
			while (times--) ans += copy;
		}
		else if (c == ']')return ans;
		else ans += c;
	}

}
int main()
{   
	cout << f();
}