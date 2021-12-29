#include <bits/stdc++.h>
using namespace std;

vector<int>v;
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
    for(int i = 0;i < n;i++){
        int data;
        scanf("%d",&data);
        v.push_back(data);
    }
    int i,j;
    for(i = 1;i < n;i++){
        int m = v[i];
        for(j = i - 1;j >= 0 && v[j] > m;j--){
            v[j + 1] =  v[j];
        }
        v[j + 1] = m;
        for(int i = 0,sz = v.size();i < sz - 1;i++)
            printf("%d ",v[i]);
        printf("%d\n",v[v.size() - 1]);
    }
    v.clear();
    }
    return 0;
}