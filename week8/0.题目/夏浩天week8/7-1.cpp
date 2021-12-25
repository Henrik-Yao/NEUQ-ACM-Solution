#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct act
{
    int q1, q2;
};

bool cmp(act a1, act a2)
{
    return (a1.q2 < a2.q2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;vector<act>a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].q1 >> a[i].q2;
        }
        sort(a.begin(), a.end(), cmp);
        int gs = 1;//参加活动次数
        int ent = a[0].q2;
        for (int i = 1; i < n; i++)
        {
            if (a[i].q1 >= ent)
            {
                gs++;
                ent = a[i].q2;
            }
        }
        cout << n - gs << endl;
    }
}