#include <iostream>
using namespace std;
void hnt(int, string, string, string);
main()
{

    string a, b, c;
    int n;
    
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    hnt(n, a, b, c);
}
void hnt(int n, string a, string b, string c)
{
    if (n == 1)
    {
        cout << a << "->" << c << endl;
        return;
    }
    hnt(n - 1, a, c, b);
    cout << a << "->" << c<<endl;
    hnt(n - 1, b, a, c);
    return;
}
