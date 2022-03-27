#include<iostream>
using namespace std;
int jl[1000001];
int jl1[1000001];
int main()
{
    int n, cs = 0, now = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> jl[i];
    jl1[1] = jl[1] + 1;
    for (int i = 2; i <= n; i++)
        jl1[i] = max(jl1[i - 1], jl[i] + i);
    while (1)
    {
        now = jl1[now];
        cs++;
        if (now >= n) break;
    }
    cout << cs;
}