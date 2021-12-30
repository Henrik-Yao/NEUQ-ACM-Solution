#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N],s[N];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
sort(a,a+n);
for(int i = 0; i < n; i++)
s[a[i]]++;
    for(int i = 0; i < 50; i++){
   
          if(a[i]!=a[i+1])
        cout<<a[i]<<" "<<s[a[i]]<<endl;
    }
}
