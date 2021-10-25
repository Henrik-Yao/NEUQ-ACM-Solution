#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    string b;
    string a;
    cin >> n >> b;
    for (int i = 0;i < n;i++)
    {
        cin >> a;
        int cd = a.size();
        int gs2 = 0;//计数
        for (int j = 0;j < b.size();j++)
        {
            int pd = 0;//判断是否完整
            if (a[0] == b[j]&&a.size()>1)
            {
                for (int j1 = 1;j1 < cd;j1++)
                {
                    pd = 1;
                    if (a[j1] != b[j + j1])
                    {
                        pd = 0;
                        break;
                    }
                }
            }
            if (a.size() == 1&& a[0] == b[j])
            {
                gs2++;
            }
            if (pd == 1)
            {
                gs2++;
            }
        }
        if(i<n-1)
        cout << gs2 << endl;
        if(i==n-1)
            cout << gs2;
    }
}