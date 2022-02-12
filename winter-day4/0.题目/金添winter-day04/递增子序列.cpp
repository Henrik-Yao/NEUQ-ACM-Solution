#include <bits/stdc++.h>
using namespace std;
int a[100], num, len;
vector<int> ans[1000];
bool visit[1000];
void search(int i, int n)
{
    ans[n].push_back(a[i]);
    for (int j = i + 1; j < len; j++)
    {
        if (a[j] >= a[i])
        {
            ans[++num] = ans[n];
            // for (int k = 0; k < ans[n].size(); k++)
            //     ans[num].push_back(ans[n][k]);
            search(j, num); //继承进度，继续搜索
        }
    }
}
int main()
{
    cin >> len;
    for (int i = 0; i < len; i++)
        cin >> a[i];
    for (int i = 0; i < len; i++)
    {
        search(i, num);
        num++;
    }
    // for(int i=0;i<num;i++)
    // {
    //     for(int j=0;j<ans[i].size();j++)
    //     cout<<ans[i][j]<<" ";
    //     cout<<endl;
    // }
    int real = 0; //真正的答案
    map<vector<int>, int> contain;
    for (int i = 0; i < num; i++)
    {
        if (ans[i].size() >= 2)
            ;
        else
            continue;
        if (contain[ans[i]])
            continue;
        else
        {
            real++;
            contain[ans[i]] = 1;
        }
    }
    cout << real;
    return 0;
}