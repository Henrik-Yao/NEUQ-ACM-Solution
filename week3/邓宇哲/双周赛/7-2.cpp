#include <iostream>
using namespace std;
void hannuota(int, string, string, string);
main()
{
    string a, b, c;
    int n;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    hannuota(n, a, b, c);
}
void hannuota(int n, string a, string b, string c)
{
    if (n == 1)
    {
        cout << a << "->" << c << endl;
        return;
    }
    hannuota(n - 1, a, c, b);
    cout << a << "->" << c<<endl;
    hannuota(n - 1, b, a, c);
    return;
}
