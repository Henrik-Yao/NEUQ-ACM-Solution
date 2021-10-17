#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int n; cin >> n;
    string s, temp; cin >> s;
    vector<string>mode;
    for (size_t i = 0; i < n; i++)
    {
        cin >> temp;
        mode.push_back(temp);
    }
    for (auto c : mode)
    {
        int sum = 0;
        auto it = s.begin();
        while (it != s.end()) {
            it = search(it, s.end(), c.begin(), c.end());
            if (it != s.end()) {
                ++sum;
                ++it;
            }
        }
        cout << sum << endl;
    }
}