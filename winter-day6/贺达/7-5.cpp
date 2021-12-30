#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

int h[N];
int n, m, len;

void down(int x)
{
    if(x * 2 > len)
    {
        return;
    }
    int u = x;
    if(h[u] < h[x * 2] && x * 2 <= len)
    {
        u = x * 2;
    }
    if(h[u] < h[x * 2 + 1] && x * 2 + 1 <= len)
    {
        u = x * 2 + 1;
    }
    if(u != x)
    {
        swap(h[x], h[u]);
        down(u);
    }

}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        cin >> h[i];
    }

    len = n;
    for(int i = n / 2; i > 0; i--) 
    {
        down(i);
    }
    int r = n;
    while(r -- )
    {
        for(int i = 1; i <= n; i ++)
        {
            cout<<h[i]<<" ";
        }
        cout << endl;
        swap(h[1], h[len]);
        len--;
        down(1);
    }
    return 0;
}
