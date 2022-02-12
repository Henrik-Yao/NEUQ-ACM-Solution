#include<iostream>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;

const int maxn = 10000, infanity = 1e5;
int d[maxn][maxn];
int fa[maxn][maxn];
int n;

void Floyd() 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fa[i][j] = i;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    fa[i][j] = fa[k][j];
                }
            }  
        }
    }
}

int main() {
    int e, x, y;
    cin >> n >> e;
    for (int i = 0; i < n; i++) 
    {
        d[i][i] = 0;
        for (int j = i + 1; j < n; j++) 
        { 
            d[i][j] = d[j][i] = infanity; 
        }
    }
    for (int i = 0; i < e; i++)
    {
        cin >> x;
        cin >> y;
        cin >> d[x][y];
    }

    Floyd();

    int maxd = 0, maxi, maxj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && d[i][j] != infanity)
            {
                if (d[i][j] > maxd)
                {
                    maxd = d[i][j];
                    maxi = i;
                    maxj = j;
                }
            }
        }
    }
        
    for (int i = 0; i < 2; i++) {
        cin >> x >> y;
        if (x == y)
        {
            cout << x << "->" << y << ":" << 0<<endl;
        }
        else if (d[x][y] >= infanity)
        {
            cout << x << "->" << y << ":" << -1<<endl;
        }
        else 
        {
            stack<int>ans;
            int ix = x, jy = y;
            while (fa[ix][jy] != x) 
            {
                ans.push(fa[ix][jy]);
                jy = fa[ix][jy];
            }
            cout << x;
            while (!ans.empty()) 
            {
                cout << "->" << ans.top();
                ans.pop();
            }
            cout << "->" << y;
            cout << ":" << d[x][y]<<endl;
        }
    }
    stack<int>ans;

    int ix = maxi, jy = maxj;
    while (fa[ix][jy] != ix) 
    {
        ans.push(fa[ix][jy]);
        jy = fa[ix][jy];
    }
    cout << maxi;
    while (!ans.empty()) 
    {
        cout << "->" << ans.top();
        ans.pop();
    }
    cout << "->" << maxj;
    cout << ":" << d[maxi][maxj];
    return 0;
}