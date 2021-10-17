#include <bits/stdc++.h>
using namespace std;

const int max_N = 4e6+1e3;
char s[max_N];
string a;
int main(){
    int n,i;
    scanf("%d",&n);
    scanf("%s",s+1);
    int now = strlen(s + 1);
    for(int i = 1;i <= n;i++){
        int num = 0;
        cin>>a;
        int len = a.length();
        for(int i = 1;i <= now - len + 1;i++){
        string b;
        b.clear();
        for(int j = i;j <= i + len - 1;j++) b += s[j];
            if(a == b) ++num;
    }
    cout<<num;
    if(i != n) cout<<"\n";
    }
    return 0;
}
