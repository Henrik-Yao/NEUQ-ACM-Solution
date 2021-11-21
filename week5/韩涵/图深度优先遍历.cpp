/*#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Point {
    int start;
    int next;
    bool thought;
};

Point rope[51];
bool num[20001] = { 0 };
int n, e;

bool cmp(Point a, Point b) {
    if (a.start == b.start)return a.next < b.next;
    else return a.start < b.start;
}

void search(int a) {
    for (int i = 0; i < e; i++) {
        if (!rope[i].thought) continue;
        if (rope[i].start == a) {
            rope[i].thought = false;
            int temp = rope[i].next;
            if (num[temp]) {
                cout << temp << " ";
                num[temp] = false;
            }
            search(temp);
        }

    }

}

int main() {
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        cin >> rope[i].start >> rope[i].next;
        rope[i].thought = true;
    }
    for (int i = 0; i <= n; i++) num[i] = true;
    sort(rope, rope + e, cmp);
    for (int i = 0; i < n; i++) {
        if (num[i]) {
            cout << i << " ";
            num[i] = false;
        }
        search(i);
    }

}*/