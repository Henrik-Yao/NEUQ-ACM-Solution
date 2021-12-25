/*#include<iostream>
#include<ctime>
using namespace std;

int r0[100000001];
int n;
int ans;
int endi, first = 0;

int maxi(int first, int endi) {
    int max = 0;
    for (int i = first; i <= endi; i++) {
        max = max > r0[i] + i ? max : r0[i] + i;
    }
    return max;
}

int main() {
    //time_t begin, end;
    //double ret;
    //begin = clock();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r0[i];
    }
    endi = r0[first] + first;
    for (ans = 0; first < n - 1; ans++) {
        int temp = endi;
        endi = maxi(first, endi);
        first = temp;
        cout << endi << first << endl;
    }
    cout << ans <<endl;
    //end = clock();
    //ret = double(end - begin) / CLOCKS_PER_SEC;
    //cout << "runtime:   " << ret << endl;
}*/