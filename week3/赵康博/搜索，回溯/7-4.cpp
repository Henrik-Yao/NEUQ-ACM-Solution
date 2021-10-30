#include <iostream>

using namespace std;
int n;
char f[1001][1001];
int s[1001][1001];
int sum = 0;
void df(int x,int v,int i){
    sum++;
    s[x][v] = i + 1;
    if(x>1&&s[x-1][v]==0&&(f[x-1][v]!=f[x][v]))df(x-1,v,i);
    if(v>1&&s[x][v-1]==0&&(f[x][v-1]!=f[x][v]))df(x,v-1,i);
    if(v<n&&s[x][v+1]==0&&(f[x][v+1]!=f[x][v]))df(x,v+1,i);
    if(x<n&&s[x+1][v]==0&&(f[x+1][v]!=f[x][v]))df(x+1,v,i);
}

int main() {
    int m;
    cin>>n>>m;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            cin>>f[i][j];
        }
    }
    int x,v;
    int cun1[m+1];
    for (int i = 0; i < m; ++i) {
        cin>>x>>v;
        if(s[x][v]!=0){
            cout<<cun1[s[x][v]]<<endl;
            continue;
        }
        df(x,v,i);
        cout<<sum<<endl;
        cun1[i+1] = sum;
        sum = 0;

    }
    return 0;
}