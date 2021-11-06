#include<bits/stdc++.h>
using namespace std;


int cnt=0;
bool visit[10000010];
void Prime(int n)
{

    visit[0] = visit[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!visit[i])
        {
            cnt++;
            for (int j = 2*i; j <= n; j += i)
            {
                visit[j] = 1;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    Prime(n);
    cout<<cnt;

    return 0;
}

