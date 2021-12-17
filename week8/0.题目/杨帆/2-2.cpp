#include<bits/stdc++.h>
using namespace std;
const int k = 1e6+5;
int w[k];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    int next,ans = 0;
    for(int i=1;; i=next){
        int temp = 0,iden = 0;
        for(int j=1; j<=w[i]; j++){
            if(temp < i+j+w[i+j]){
            	temp = i+j+w[i+j];
            	iden = i + j;
			}
        }
        next = iden;
        ans++;
        if(next+w[next] >= n){
            ans++;
            break;
        }
    }
    cout << ans;
}
