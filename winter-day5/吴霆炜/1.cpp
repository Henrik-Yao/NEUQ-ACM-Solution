#include <bits/stdc++.h>
using namespace std;

vector<int>a;
int n;
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int data;
        scanf("%d",&data);
        a.push_back(data);
    }
    sort(a.begin(),a.end());
    int cnt = 0;
    for(int i = 0,sz = a.size();i < sz - 1;i++)
        if(a[i] == a[i + 1] - 1) cnt++;
    printf("%d\n",cnt);
    return 0;
}