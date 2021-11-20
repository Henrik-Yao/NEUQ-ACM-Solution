#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> peo;
struct family
{
    char sex;
    int father = -1;
    int mother = -1;
} f[100001];

void dfs(int num, int n)
{
    if (n == 0)
        return;
    if (f[num].father != -1)
    {
        peo.push_back(f[num].father);
        dfs(f[num].father, n - 1);
    }
    if (f[num].mother != -1)
    {
        peo.push_back(f[num].mother);
        dfs(f[num].mother, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        cin >> f[p].sex >> f[p].father >> f[p].mother;
        if(f[p].father!=-1) f[f[p].father].sex='M';
		if(f[p].mother!=-1) f[f[p].mother].sex='F'; 
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int flag = 1, a, b;
        peo.clear();
        cin >> a >> b;
        if (f[a].sex == f[b].sex)
        {
            flag = -1;
            cout << "Never Mind";
        }
        else
        {
            dfs(a, 4);
            dfs(b, 4);
            sort(peo.begin(), peo.end());
            for (int i = 1; i < peo.size(); i++)
            {
                if (peo[i - 1] == peo[i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 1)
            cout << "Yes";
        else if (flag == 0)
            cout << "No";
        if (i != n)
            cout << "\n";
    }
    return 0;
}
