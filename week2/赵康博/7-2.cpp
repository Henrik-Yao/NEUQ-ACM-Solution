#include <iostream>
using namespace std;
void Clear(int f[],int n){
    for (int i = 0; i < n; ++i) {
        f[i] = 0;
    }
}
typedef struct {
    int a;
    int b;
}Lu;
int main() {
   int n,m;
   cin>>n>>m;
   Lu s[m];
    for (int i = 0; i < m; ++i) {
     cin>>s[i].a>>s[i].b;
    }
    int k;
    cin>>k;
    for (int i = 0; i < k; ++i) {
        int f[n] ;
        int p = 0;
        Clear(f,n);
        int x;
        cin>>x;
        for (int j = 0; j < x; ++j) {
            int t;
            cin>>t;
            f[t-1] = 1;
        }
        for (int j = 0; j < m; ++j) {
            if(f[s[j].a-1]!=1&&f[s[j].b-1]!=1){
                cout<<"NO"<<endl;
                p = 1;
                break;
            }
        }
        if(p == 0){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
