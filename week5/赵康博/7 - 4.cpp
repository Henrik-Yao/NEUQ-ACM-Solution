#include <bits/stdc++.h>
#define N 2010
using namespace std;
int m,n;
int s[N][N];
int v[N][N];
int a1[4] = {0,1,0,-1};
int b1[4] = {1,0,-1,0};
void p(int a,int b){
    v[a][b] = 1;
    for (int i = 0; i < 4; i++)
    {
    if(s[a+a1[i]][b+b1[i]]==1&&v[a+a1[i]][b+b1[i]]==0)p(a+a1[i],b+b1[i]);
    }
}

int main(){
    int sum = 0;
    cin>>m>>n;
    for(int i = 1; i <= m;i ++){
        for (int j = 1; j <= n; j++)
        {
            cin>>s[i][j];
        }
    }
    for(int i = 1;i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i][j] == 1&&v[i][j] == 0){
                sum++;
                p(i,j);
        }
    }
    } 
    cout<<sum;
    return 0;
}