#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 10010;

string a[5];

void output(int x, int y, int n)
{
    if(!n) return;
    int ex;
    for(int i = 1; i <= 3; ++i)
        if(i != x && i != y) ex = i;
    output(x, ex, n - 1);
    cout << a[x] << "->" << a[y] << "\n";
    output(ex, y, n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cin >> a[1] >> a[2] >> a[3];
    output(1, 3, n);
    return 0;
}