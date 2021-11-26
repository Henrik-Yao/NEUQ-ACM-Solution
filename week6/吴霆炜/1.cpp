#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010

char s1[maxn],s2[maxn];
int j;
int kmp[maxn];
int len1,len2;
int cnt;
int main(){
    cin>>s1 + 1;
    cin>>s2 + 1;
    len1 = strlen(s1 + 1);
    len2 = strlen(s2 + 1);
    for(int i = 2;i <= len2;i++){
        while(j && s2[i] != s2[j + 1])
            j = kmp[j];
            if(s2[j + 1] == s2[i])j++;
            kmp[i] = j;
    }
    j = 0;
    for(int i = 1;i <= len1;i++){
        while(j > 0 && s2[j + 1] != s1[i])
        j = kmp[j];
        if(s2[j + 1] == s1[i])
        j++;
        if(j == len2){
            cnt++;
            j = kmp[j];
        }
    }
    cout<<cnt;
    return 0;
}