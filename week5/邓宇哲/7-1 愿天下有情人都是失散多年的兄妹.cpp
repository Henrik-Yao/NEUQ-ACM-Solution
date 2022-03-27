#include <algorithm>
#include <iostream>
using namespace std;
int path1[100] = {0};
int path2[100] = {0};
int depth1 = 0, deep1 = 0;
int depth2 = 0, deep2 = 0;
void bfs(int, int);
struct people
{
    char sex;
    int fid = -1;
    int mid = -1;
    int layer;
};
people guy[100000];
main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        cin >> guy[id].sex >> guy[id].fid >> guy[id].mid;
        if (guy[id].fid != -1)
        {
            guy[guy[id].fid].sex = 'M';
        }
        if(guy[id].mid!=-1)
        {
            guy[guy[id].mid].sex = 'F';
        }
    }
    cin >> n;
    int i;
    for (i = 0; i < n; i++)
    {
        depth1 = 0, depth2 = 0;
        int g1, g2;
        cin >> g1 >> g2;
        if (guy[g1].sex == guy[g2].sex)
        {
            cout << "Never Mind" << endl;
            continue;
        }
        bfs(g1, 1), bfs(g2, 2);
        deep1 = 0, deep2 = 0;
        bool done = 0;
        for (int k = 0; k < depth1; k++)
        {
            for (int l = 0; l < depth2; l++)
            {
                if (path1[k] == path2[l])
                {
                    done = 1;
                    break;
                }
            }
            if (done == 1)
            {
                break;
            }
        }
        if (i != n - 1)
        {
            if (done == 1)
            {
                cout << "No" << endl;
            }
            else
                cout << "Yes" << endl;
        }
        else
        {
            if (done == 1)
            {
                cout << "No";
            }
            else
                cout << "Yes";
        }
    }
}
void bfs(int s, int j)
{
    if (s == -1)
    {
        return;
    }
    if ((deep1 == 5 && j == 1) || (deep2 == 5 && j == 2))
    {

        return;
    }

    if (j == 1)
    {
        path1[depth1++] = s;
        deep1++;
        bfs(guy[s].fid, 1);
        bfs(guy[s].mid, 1);
        deep1--;
    }
    else
    {
        path2[depth2++] = s;
        deep2++;
        bfs(guy[s].fid, 2);
        bfs(guy[s].mid, 2);
        deep2--;
    }
}