#include <iostream>
using namespace std;
typedef struct {
    int a;
    char b[10];
}stu;
typedef struct {
    int a;
    int b;
}xu;
int main(){
    int n,m;
    cin>>n>>m;
    stu f[n];
    xu s[m];
    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin>>f[i].a>>f[i].b;
    }
    for (int i = 0; i < m; ++i) {
        cin>>s[i].a>>s[i].b;
    }
    for (int i = 0; i < m; ++i) {
        if(f[k].a==s[i].a)k = (k - s[i].b + n)%n;
        else k = (k + s[i].b)%n;
    }
    cout<<f[k].b;
    return 0;
}