#include <bits/stdc++.h>
using namespace std;
#define maxn 10000001

struct act{
    int a;
    int b;
}acy[maxn];

int T,n;
bool cmp(act x,act y){
    return x.b < y.b;
}

int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int cnt = 1;//排序后第一个活动默认直接参加
        for(int i = 0;i < n;i++) cin>>acy[i].a>>acy[i].b;
        sort(acy,acy + n,cmp);
        int j  = 0;
        for(int i = 1;i < n;i++){
            if(acy[i].a >= acy[j].b){
                j = i;
                cnt++;
            }
        }
        cout<<n - cnt<<endl;
    }
    return 0;
}