#include <iostream>

using namespace std;

const int N = 100;

int m, n, k;

int main()
{
    cin >> m >> n >> k;
    int arcs[N][N];
    int safeCities[n];
    for (int i = 0; i < n; i++) cin >> safeCities[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arcs[i][j] = 0;
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        arcs[a][b] = arcs[b][a] = 1;
    }
    int from, to, safe = 0;
    cin >> from >> to;
    for (int i = 0; i < n; i++) {
        if (to == safeCities[i]) {
            safe = 1;
            break;
        }
    }
    if (safe == 0) {
        printf("The city %d is not safe!", to);
    } else if (arcs[from][to] == 1) {
        printf("The city %d can arrive safely!", to);
    } else {
        printf("The city %d can not arrive safely!", to);
    }
    return 0;
}

