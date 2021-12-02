/*#include<iostream>
using namespace std;

int r0[100000001];
int n;
int ans;
int first = 0;

int findnum(int first, int endi) {
    int max = 0,temp = first + 1;
    for (int i = first; i < endi; i++) {
        if (max > r0[i]) {
            max = r0[i];
            temp = i; 
        }
    }
    return temp;
}

int linknum(int n, int m) {
    int ans = n;
    for (int i = ans; i <= m; i++) {
        if (r0[n] < r0[i] + (i - n)) {
            n = i;
        }
    }
    return n;
}

int main() {
    time_t begin, end1;
    double ret;
    begin = clock();


    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r0[i];
    }
    for (ans = 1; first + r0[first] < n - 1; ans++) {
        int temp = r0[first];
        int local = findnum(first, first + r0[first]);
        first = linknum(local, first + temp);

    }
    cout << ans;

     
    end1 = clock();
    ret = double(end1 - begin) / CLOCKS_PER_SEC;
    cout << "runtime:   " << ret << endl;
}*/