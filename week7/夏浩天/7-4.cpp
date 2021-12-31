#include <iostream>
using namespace std;
int t;
int a[10000], gs[10000];
int main()
{
    cin >> t;
    for(int qw=0;qw<t;qw++)
    {
        if(qw)cout<<endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            gs[i] = 1;
        }
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j < i; j++) 
            {
                if (a[j] < a[i]) 
                    gs[i] = max(gs[i], gs[j] + 1);
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) 
            ans = max(ans, gs[i]);
        cout << ans << endl;
    }
}