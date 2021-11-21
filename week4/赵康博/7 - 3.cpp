#include <iostream>
#include <cstring>
using namespace std;
int f[10002000]; //储存素数
bool s[10002000]; 
int main(){
    int b;
    cin>>b;
        int n = 0;
        memset(s,false,sizeof(s));
        for (int i = 2; i <= b; ++i) {
            if (!s[i])f[n++] = i;
            for (int j = 0; j < n && i * f[j] <= b; ++j) {
                s[f[j] * i] = true;
                if (i % f[j] == 0)break;
            }
        }
        cout<<n;
        cout << endl;
    return 0;
}