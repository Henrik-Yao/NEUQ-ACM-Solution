#include<bits/stdc++.h>
using namespace std;

int n, m;
pair<int, string> p[100010];

//0顺 1逆
int get(int op, int pos, int num)
{
    num %= n;
    if(op == 1)
    {
        pos += num;
        if(pos > n) pos -= n;
    }
    if(op == 0)
    {
        pos -= num;
        if(pos <= 0) pos += n;
    }
    return pos;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
    int now = 1;
    while(m--)
    {
        int op, num;
        cin >> op >> num;
        int todo;
        if(op == 0)
        {
            if(p[now].first == 0) todo = 0;
            else todo = 1;
        }
        else
        {
            if(p[now].first == 0) todo = 1;
            else todo = 0;
        }

        now = get(todo, now, num);
    }
    cout << p[now].second << endl;
    return 0;
}