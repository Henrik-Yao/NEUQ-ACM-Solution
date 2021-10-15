#include <iostream>

using namespace std;

struct stu {
    int to;
    string name;
};

int main() {
    int n, m;
    cin >> n >> m;
    stu stus[n];
    for (int i = 0; i < n; i++) {
        cin >> stus[i].to >> stus[i].name;
    }
    int a, b,index = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a == stus[index].to) {
            index -= b;
        } else {
            index += b;
        }
        if (index < 0) {
            index = n + index;
        }
        if (index > n - 1) {
            index = index - n;
        }
    }
    cout << stus[index].name;
    return 0;
}

