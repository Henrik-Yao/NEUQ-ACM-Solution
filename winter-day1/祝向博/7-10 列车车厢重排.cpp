#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int N,Ans,a[maxn];
vector <int> fst;
int main() {
    scanf("%d",&N);
    a[0]=N+1;
    for (; N--; ) {
        int x,id=0;
        scanf("%d",&x);
        for (int i=1; i<=Ans; ++i) if (a[i]>x&&a[i]<a[id]) id=i;
        if (id==0) a[++Ans]=x;
        else a[id]=x;
        if (id==1 || id==0&&Ans==1) fst.push_back(x);
    }
    for (int i=0; i<fst.size()-1; ++i) printf("%d ",fst[i]);
    printf("%d\n%d\n",fst[fst.size()-1],Ans);
    return 0;
}
