/*#include<iostream>
#include<algorithm>
using namespace std;

struct Program {
    int start;
    int end;
};

bool cmp(Program p1, Program p2) {
    return(p1.end < p2.end);
}

Program pro[1000001];
int n;

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pro[i].start >> pro[i].end;
    }
    sort(pro, pro + n, cmp);
    int cnt = 1;
    int curEnd = pro[0].end;
    for (int j = 1; j < n; j++) {
        if (pro[j].start >= curEnd) {
            cnt++;
            curEnd = pro[j].end;
        }
    }
    cout << n - cnt << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        run();
    }
    return 0;
}*/