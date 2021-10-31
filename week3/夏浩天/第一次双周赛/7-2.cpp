#include<iostream>
#include<string.h>
using namespace std;
void dg(int n, string a, string b, string c)
{
    if (n == 1)cout << a << "->" << c << endl;
    else if(n>1)
    {
    dg(n - 1, a, c, b);
    dg(1, a, b, c);
    dg(n - 1, b, a, c);
    }
}
int main()
{
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    dg(n, a, b, c);
}