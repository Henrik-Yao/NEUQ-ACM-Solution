#include<iostream>
#include<cstring>
using namespace std; 

int main(){ 
    int n,m;
    int a[2100]={0},b[2100]={0},c[2100]={0};
    while(cin >> n >> m){
        memset(b,0,sizeof b), memset(c,0,sizeof c), memset(a,0,sizeof a); 
        for(int i=1; i<=n; i++){ 
            cin >> b[i]; 
        } 
        for(int i=1; i<=n; i++){ 
            cin >> c[i]; 
        } 
        for(int i=1; i<=n; i++){     
            for (int j=m; j>=b[i]; j--){ 
                a[j] = max(a[j], a[j-b[i]] + c[i]); 
            } 
        } 
        cout << a[m] << endl; 
    } 
    return 0;
    
    
}
