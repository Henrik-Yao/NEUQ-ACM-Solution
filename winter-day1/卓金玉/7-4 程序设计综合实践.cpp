#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    list<int> l, jishu, oushu;
    while (scanf("%d", &num) != EOF)
    {
        l.push_back(num);
        if (!(num % 2))
        {
            oushu.push_back(num);
        }
        else
        {
            jishu.push_back(num);
        }
    }
    l.sort();
    oushu.sort();
    jishu.sort();
    int temp;
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        if (it != l.begin())
        {
            printf("->");
        }
        temp = *it;
        printf("%d", temp);
    }
    printf("\n");
    for (auto it = jishu.begin(); it != jishu.end(); ++it)
    {
        if (it != jishu.begin())
        {
            printf("->");
        }
        temp = *it;
        printf("%d", temp);
    }
    printf("\n");
    for (auto it = oushu.begin(); it != oushu.end(); ++it)
    {
        if (it != oushu.begin())
        {
            printf("->");
        }
        temp = *it;
        printf("%d", temp);
    }

    return 0;
}