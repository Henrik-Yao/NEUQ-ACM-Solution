#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
int a[N], b[N];
vector<int> vec;
set<int> st;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        st.insert(a[i]), vec.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        st.insert(b[i]), vec.push_back(b[i]);
    }
//     cout << st.size() << endl;
    sort(vec.begin(), vec.end());
//     for (auto &item : vec) cout << item << " ";
    cout << vec[(n * 2 - 1) / 2] << endl;
    return 0;
}