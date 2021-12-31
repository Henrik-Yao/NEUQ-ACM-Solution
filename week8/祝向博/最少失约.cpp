#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;

int T,N,Ans,lst;

struct event {int L,R;}a[maxn];
inline bool operator <(event a,event b) {
    return a.L<b.L||a.L==b.L&&a.R<b.R;
}

int main() {
    for (cin>>T; T--; ) {
        cin>>N;
        for (int i=1; i<=N; ++i)
            cin>>a[i].L>>a[i].R;
        sort(a+1,a+1+N);
        Ans=0,lst=-1;
        for (int i=1; i<=N; ++i) {
            if (a[i].L>=lst) Ans++,lst=a[i].R;
            else if (a[i].R<lst) lst=a[i].R;
        }
        printf("%d\n",N-Ans);
    }
    return 0;
}
