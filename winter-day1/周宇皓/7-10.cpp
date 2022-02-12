#include<iostream>
using namespace std;
const int N = 100010;
int a[N][N],s[N][N];
int main(){
    int m,n,k;
    cin>>m>>n>>k;
    for(int i = 1;i <= m; i++)
    for(int j = 1; j <= n; j++){
        cin>>a[i][j];
    }
    for(int i = 1;i <= m; i++)
    for(int j = 1; j <= n; j++)
    s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    while(k--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<(s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]);
    }
}
