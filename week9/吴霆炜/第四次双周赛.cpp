#include <bits/stdc++.h>
using namespace std;
#define fd(i,l,r) for(register int i = l;i <= r;i++)

int n,m,cnt,_ans;
vector<int>vec,p;
int main(){
    scanf("%d %d",&n,&m);
    fd(i,0,n - 1){
        int data;
        scanf("%d",&data);
        vec.push_back(data);
    }
    sort(vec.begin(),vec.end());
    p.resize(n - 1);
    fd(i,1,n - 1)
        p[cnt++] = vec[i] - vec[i - 1] - 1;
    sort(p.begin(),p.end());
    fd(i,0,n - m - 1)
    _ans += p[i];
    printf("%d\n",_ans + n);
    return 0;
}