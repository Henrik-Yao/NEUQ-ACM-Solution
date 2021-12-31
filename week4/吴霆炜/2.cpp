#include <bits/stdc++.h>
using namespace std;
#define maxn 100000010

int ans[maxn];
int main(){
    int N;
    cin>>N;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 2;
    for(int i = 4;i <= 40;i++)
        ans[i] = ans[i - 1] + ans[i - 2];
    while(N--){
        int M;
        cin>>M;
        cout<<ans[M]<<endl;
    }
    return 0;
}