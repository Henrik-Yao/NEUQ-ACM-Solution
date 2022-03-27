#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int q[1002];
int c = 0;//层数(高度)
bool flag;
void mid(int n, int cs)
{
    if (q[n] == 0) return;
    c = max(c, cs);
    mid(n * 2, cs + 1);
    if (flag == 0)
    {
        cout << q[n];
        flag = 1;
    }
    else
        cout << ' ' << q[n];
    mid(n * 2 + 1, cs + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        flag = 0;
        memset(q, 0, 1002);
        c = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin>>q[i];
        mid(1, 1);
        cout << endl;
        cout << c << endl;
    }
}