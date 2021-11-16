#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct co{
    int a;
    int b;
}co;

bool cmp(co a,co b){
    if(a.a<b.a)return true;
    if(a.a>b.a)return false;
    if(a.b<b.b)return true;
    if(a.b>b.b)return false;
}
vector<int> s[20000];
int v[20000];
int n;
int sum = 0;
void f(int m){
    cout<<m<<" ";
    v[m] = 1;
    sum++;
    for(int t : s[m]){
        if(v[t]==0){
            v[t] = 1;
            f(t);
        }
    }
}

int main(){
    int e;
    cin>>n>>e;
    memset(v,0, sizeof(v));
    v[0] = 1;
    co m1[e];
    for (int i = 0; i < e; ++i) {
        cin>>m1[i].a>>m1[i].b;
    }
    sort(m1,m1+e,cmp);
    for (int i = 0; i < e; ++i) {
        s[m1[i].a].push_back(m1[i].b);

    }
    int min = 0;
    while (sum != n) {
        f(min);
        for (int i = min; i < n; ++i) {
            if(v[i]==0){
                min = i;
                break;
            }
        }
    }
    return 0;
}