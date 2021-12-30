#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N],s[N];
int main(){
    int n,x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>x;
        s[x]++;
    }
    for(int i = 0; i <= 50; i++){
   
          if(s[i])
        cout<<i<<":"<<s[i]<<endl;
    }
}
