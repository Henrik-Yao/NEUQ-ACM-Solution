#include<bits/stdc++.h>
#define N 100000
using namespace std;
int main()
{
    int a[N],b[N],c[2*N];
    int n,i,ai=0,bi=0;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (i=0; i<n; i++) {
        scanf("%d",&b[i]);
    }
    
    for (i=0; i<2*n; i++) {
        
        if (a[ai]<=b[bi]) {
            c[i]=a[ai];
            ai++;
        }
        else{
            c[i]=b[bi];
            bi++;
        }
        
    }
    
    printf("%d\n",c[(2*n-1)/2]);
    
    
}
