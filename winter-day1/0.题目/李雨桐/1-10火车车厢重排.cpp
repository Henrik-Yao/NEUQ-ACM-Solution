#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q[105];
    int res=0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        {
        int x;
        cin >> x;
        int flag=0;
        for(int j=0;j<res;j++)
        {
            if(q[j].back()>x)
            {
                q[j].push(x);
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            q[res].push(x);
            res++;
        }
    }
    for(int i=0;i<res;i++)
    {
        if(q[i].back()==1)
        {
            while(!q[i].empty())
            {
                cout << q[i].front();
                q[i].pop();
                if(!q[i].empty())
                 cout<<' ';
                else cout<<endl;
            }
            break;
        }
    }
    cout<<res<<endl;

    return 0;
}
