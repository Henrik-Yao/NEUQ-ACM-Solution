#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
using namespace std;
class que
{
public:
    int a[1024];
    int length = 0;
};
main()
{
    int n, num = 0, pointmin = 0, pointmax = 0, point = 0;

    cin >> n;
    int queue[n];
    for (int i = 0; i < n; i++)
    {
        cin >> queue[i];
    }
    que p[128];
    map<int, int> mp;
    int minlist[128] = {};
    for (int i = 0; i < n; i++)
    {
        int maxs = 0;
        for (int j = 0; j < num; j++)
        {
            
            if (maxs < p[j].a[p[j].length - 1])
            {
                pointmax = j;
                maxs = p[j].a[p[j].length - 1];
            }
            minlist[j] = p[j].a[p[j].length - 1];
            mp[p[j].a[p[j].length - 1]] = j;
        }
        if (maxs < queue[i])
        {
            point = num;
            p[point].a[p[point].length++] = queue[i];
            num++;
            continue;
        }
        sort(minlist, minlist + num);
        for (int t = 0; t < num; t++)
        {
            if (minlist[t] > queue[i])
            {
                point = mp[minlist[t]];
                break;
            }
        }
        p[point].a[p[point].length++] = queue[i];
    }

    for (int i = 0; i < p[0].length-1; i++)
    {
        cout << p[0].a[i] << ' ';
    }

    cout<<p[0].a[p[0].length-1] << endl;
    cout << num<<endl;
}
