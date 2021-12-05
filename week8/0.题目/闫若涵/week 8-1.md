```c++
#include<bits/stdc++.h>
using namespace std;
struct t{
    int a;
    int b;
}p[10000];
bool ta(t s1, t s2){
    return s1.b < s2.b;
}
int main()
{
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        for(int j = 0; j < n; j ++){
            cin >> p[j].a >> p[j].b;
        }
        sort(p,p+n,ta);
        int j = 0;
        int sum = 1;
        for(int i = 1; i < n; i ++){
            if(p[i].a >= p[j].b){
                j = i;
                sum ++;
            }
        }
        cout << n-sum << endl;
    }
}

```

