#include <bits/stdc++.h>
using namespace std;
const int p = 1e5+5;

int a[p],f[p];

int main(){
    int n,num;
    cin >> n >> num;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0; i<n-1; i++){
        f[i] = a[i+1] - a[i] - 1;
    }
    sort(f,f+n-1);
   int len = a[n-1] - a[0] + 1;
   int e = n-2;
   for(int i=1; i<num; i++){
       len = len - f[e];
       e--;
   }
   cout << len;
    return 0;
}
