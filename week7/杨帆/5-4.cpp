#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int num[N],m[N];

int main(){
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> num[i];
        }
        vector<int> dp(m+1,0);
        int len = 1;
        dp[len] = num[0];
        for(int i=1; i<m; i++){
            if(num[i] > dp[len]){
                dp[++len] = num[i];
            }
            else{
                int l = 1,r = len,pos = 0;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if (dp[mid] < num[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                dp[pos+1] = num[i];
            }
        }
        cout << len << "\n";
        if(n)   cout << "\n";
    }
    return 0;
}
