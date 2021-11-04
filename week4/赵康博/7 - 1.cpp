#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int a ,b;
    while (cin >> a >> b) {
        int n = 0;
        int f[1000]; //储存素数
        bool s[1000]; //
        memset(f, 0, sizeof(f));
        memset(s, false, sizeof(s));
        for (int i = 2; i <= b; ++i) {
            if (!s[i])f[n++] = i;
            for (int j = 0; j < n && i * f[j] <= b; ++j) {
                s[f[j] * i] = true;
                if (i % f[j] == 0)break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (f[i] >= a){
                cout << f[i];
                if(i!=n-1)cout<<" ";
            }
        }
        cout << endl;
    }
    return 0;
}