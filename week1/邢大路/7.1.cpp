#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    int l=s.length();
    for(int i=0;i<n;i++){
     string a;
        cin>>a;
        int count=0;
        int m=a.length();
        for(int j=0;j<=l-m;j++){
            if(s[j]==a[0]){
                int k=0;
                for(k=1;k<m;k++){
                    if(s[j+k]!=a[k])break;
                }
                if(k==m)count++;
            }
        }
        printf("%d",count);
        if(i!=n-1)cout<<endl;
    }
    return 0;
}
