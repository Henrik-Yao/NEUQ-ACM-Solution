#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

vector<int> vec[100005];
bool vis[100005];
char gender[100005];
bool flag;

void dfs(int x, int num)
{
    if (num >= 4)
    {
        return;
    }
    int u = vec[x].size();
    for (int i = 0; i < u; i++)
    {
        if (!vis[vec[x][i]])
        {
            vis[vec[x][i]] = 1;
            dfs(vec[x][i], num + 1);
        }
        else
        {
            flag = 1;
            return;
        }
    }
}

int main()
{
    int N;
    int geshu;
    cin >> N;
    while (N--)
    {
        int id;
        int father, mother;
        cin >> id;
        cin >> gender[id];
        cin >> father >> mother;
        if (father != -1)
        {
            vec[id].push_back(father);
            gender[father] = 'M';
        }
        if (mother != -1)
        {
            vec[id].push_back(mother);
            gender[mother] = 'F';
        }
    }
    cin >> geshu;
    while (geshu--)
    {
        int x, y;
        cin >> x >> y;
        if (gender[x] == gender[y])
        {
            cout << "Never Mind";
        }
        else
        {
            memset(vis, 0, sizeof(vis));
            flag = 0;
            dfs(x, 0);
            dfs(y, 0);
            if (flag)
            {
                cout << "No";
            }
            else
            {
                cout << "Yes";
            }
        }
        if (geshu != 0)
        {
            cout << endl;
        }
    }

    return 0;
}

