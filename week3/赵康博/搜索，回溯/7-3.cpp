#include <iostream>

using namespace std;

int f[21][21],s[21][21];
int sum;
int m,n;
int ss(int x,int v){
    int sum2 = 0;
    if(x>0&&f[x-1][v])sum2++;
    if(x>0&&v>0&&f[x-1][v-1])sum2++;
    if(x>0&&v<n-1&&f[x-1][v+1])sum2++;
    if(v>0&&f[x][v-1])sum2++;
    if(v<n-1&&f[x][v+1])sum2++;
    if(x<m-1&&f[x+1][v])sum2++;
    if(x<m-1&&v>0&&f[x+1][v-1])sum2++;
    if(x<m-1&&v<n-1&&f[x+1][v+1])sum2++;
    return sum2;
}

void sl(int x,int v){
    if(ss(x,v)){
        s[x][v] = ss(x,v);
        sum--;
    } else{
        sum--;
        s[x][v] = 0;
        if(x>0&&s[x-1][v]==-1)sl(x-1,v);
        if(x>0&&v>0&&s[x-1][v-1]==-1)sl(x-1,v-1);
        if(x>0&&v<n-1&&s[x-1][v+1]==-1)sl(x-1,v+1);
        if(v>0&&s[x][v-1]==-1)sl(x,v-1);
        if(v<n-1&&s[x][v+1]==-1)sl(x,v+1);
        if(x<m-1&&s[x+1][v]==-1)sl(x+1,v);
        if(x<m-1&&v>0&&s[x+1][v-1]==-1)sl(x+1,v-1);
        if(x<m-1&&v<n-1&&s[x+1][v+1]==-1)sl(x+1,v+1);
    }
}
int main() {
    int k,l;
    cin>>m>>n>>k>>l;
    sum = m*n;
    int x,v;
    for (int i = 0; i < k; ++i) {
        cin>>x>>v;
        f[x][v] = 1;
    }
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 21; ++j) {
            s[i][j] = -1;
        }
    }
    for (int i = 0; i < l; ++i) {
        cin>>x>>v;
        if(s[x][v]!=-1)continue;
        if(f[x][v]){
            cout<<"You lose"<<endl;
            return 0;
        }
        sl(x,v);
        for (int j = 0; j < m; ++j) {
            for (int z = 0; z < n; ++z) {
                cout<<s[j][z]<<" ";
            }
            cout<<endl;
        }
        if(sum==k){
            cout<<"You win"<<endl;
        }
        else
            cout<<endl;
    }
    return 0;
}