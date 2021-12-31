#include<bits/stdc++.h>
using namespace std;
void aa(){

int i = 0, j = 0;
    const int len = 10;
    int p[len] = { 0, 7, 7, 6, 1, 1, 5, 5, 8, 9 };

    sort(p, p + len);   

    while (i < len) {
        if (p[i] == p[++j]) { 
            p[j] = -1;        
        } else {
            i = j;
        }
    }

    for (i = 0; i < len; i++)
        if (p[i] != -1) 
            cout << p[i] << " ";  
}
int main()
{
    int a[51]={0},n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x,a[x]++;
    for(int i=0;i<=50;i++)
        if(a[i]) cout<<i<<":"<<a[i]<<"\n";
    return 0;
}
