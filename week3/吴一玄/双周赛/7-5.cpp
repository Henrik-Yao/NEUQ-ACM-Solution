#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int T, n, m;
    vector<int> ans;
    cin >> T;
    while(T--)
    {
        ans.clear();
        cin >> n;
        while(n--) {int x; cin >> x; ans.push_back(x);}
        cin >> n;
        while(n--) {int x; cin >> x; ans.push_back(x);}
        sort(ans.begin(), ans.end());
        cout << ans[0];
        for(int i = 1; i < ans.size(); ++i)
            cout << " " << ans[i];
        cout << "\n";
    }
}