#include <bits/stdc++.h>
using namespace std;
int main ()
{
    char s[10];
    cin>>s+1;
    int n=strlen(s+1);
    sort(s+1,s+1+n);
    do{
        cout<<s+1<<endl;
    }while(next_permutation(s+1,s+1+n));
    return 0;
}
