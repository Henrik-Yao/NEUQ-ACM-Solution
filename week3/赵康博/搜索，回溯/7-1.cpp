#include <iostream>
using namespace std;
typedef struct lu{
    int t;
    int h;
}lu;
int f[100];
lu l[100];
int m;
int k;
int s,d;
int t = 0;
void p(int n){
    if(n==d){
        t = 1;
        return;
    }
    else{
        for (int i = 0; i < k; ++i) {
            if(l[i].t == n&&f[l[i].h]==1)p(l[i].h);
            else if(l[i].h == n&&f[l[i].t]==1)p(l[i].t);
        }
    }
}
int main() {
    cin>>m;
    int n;
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        f[a] = 1;
    }
    for (int i = 0; i < k; ++i) {
        cin>>l[i].t>>l[i].h;
    }
    cin>>s>>d;
    if(f[d]==0){
        cout<<"The city "<<d<<" is not safe!";
        return 0;
    }
    p(s);
    if(t==0)cout<<"The city "<<d<<" can not arrive safely!";
    else cout<<"The city "<<d<<" can arrive safely!";
    return 0;
}