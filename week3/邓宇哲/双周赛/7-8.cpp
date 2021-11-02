#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long a, b,c=0;
    cin >> a >> b;
    for (long i = 0; i < a;i++)
    {
        long num;
        cin >> num;
        if(num>=b&&c==0)
        {
            cout << ++i<<endl;
            c=1;
        }
    }
    if(c==0)
    {cout << a + 1<<endl;}
    return 0;
}
