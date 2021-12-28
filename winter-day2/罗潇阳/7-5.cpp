#include <bits/stdc++.h>
using namespace std;

int n, m;
char str[100];
int p[100];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    getchar();
    cin >> str[i] >> p[i];
    q.push(p[i]);
  }
  int re = 0;

  while (q.size() > 1) {
    int x;
    x = q.top();
    q.pop();
    int y;
    y = q.top();
    q.pop();
    q.push(x + y);
    re = re + x + y;
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    char s[100][100];
    int sum = 0;
    for (int j = 0; j < n; j++) {
      getchar();
      char c;
      cin >> c >> s[j];
      sum = sum + strlen(s[j]) * p[j];
    }

    if (sum != re) {
			puts("No");
    } else {
      int mark = 0;

      for (int j = 0; j < n; j++) {
        int x = strlen(s[j]);
        for (int l = 0; l < n; l++) {
          if (j != l) {
            if (strstr(s[l], s[j]) == &s[l][0]) {
              mark = 1;
              break;
            }
          }
        }
        if (mark == 1) break;
      }
			puts(mark ? "No" : "Yes");
    }
  }
  return 0;
}
