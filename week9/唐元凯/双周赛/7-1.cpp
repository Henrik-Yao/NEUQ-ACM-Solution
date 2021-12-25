#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    for (size_t i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int length = a.back() - a.front() + 1;
    vector<int>space(n - 1);
    for (size_t i = 0; i < n - 1; i++)
        space[i] = a[i + 1] - a[i] - 1;
    sort(space.begin(), space.end());
    for (size_t i = 0; i < m - 1; i++)
        length -= space[n - 2 - i];
    cout << length << endl;
}