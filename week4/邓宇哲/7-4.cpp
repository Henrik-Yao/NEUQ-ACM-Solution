#include <iostream>
using namespace std;
unsigned long long fast(unsigned long long, unsigned long long,unsigned long long);
main()
{
    int n;
    cin >> n;
    unsigned long long a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        cout << fast(a, b,c)  << endl;
    }
}
unsigned long long fast(unsigned long long a, unsigned long long b, unsigned long long c)
{
    int ans = 1;
    a = a % c;
    while(b>0) {
        if(b % 2 == 1)
        ans = (ans * a) % c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}