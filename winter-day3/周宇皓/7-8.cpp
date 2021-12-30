#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
vector<int> alls;
int n;
int main(){
int a[N],b[N];
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], alls.push_back(a[i]);
   for(int i = n + 1; i <= 2*n; i++) cin >> b[i], alls.push_back(b[i]);
   sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    cout<<alls[alls.size()/2];
}
