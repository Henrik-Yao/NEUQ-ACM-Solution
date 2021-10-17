#include <iostream>

using namespace std;

int main() {
    int n,T;
    cin >> n >> T;
    int nums[n][2];
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
    }
    int res[n];
    for (int i = 0; i < n; i++) {
        int t = nums[i][1];
        int v = nums[i][0];
        if (t > T) {
            res[i] = v - (t - T);
        } else {
            res[i] = v;
        }
    }
    int max = res[0];
    for (int i = 0; i < n; i++) {
        if (res[i] >= max) {
            max = res[i];
        }
    }
    cout << max;
    return 0;
}


