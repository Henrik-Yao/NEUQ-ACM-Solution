# 题解

## 2-1

```
#include<bits/stdc++.h>
using namespace std;
const int p = 1e5;
int sta[p],end_[p];

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> sta[i] >> end_[i];
        }
        for(int i=1; i<=n-1; i++){
            for(int j=1; j<=n-i; j++){
                if(end_[j] > end_[j+1]){
                    swap(end_[j],end_[j+1]);
                    swap(sta[j],sta[j+1]);
                }
            }
        }
        int ans = 1,j = 1;
        for(int i=1; i<=n; i++){
            if(sta[i] >= end_[j]){
                j = i;
                ans++;
            }
        }
        cout << n-ans << endl;
    }
    return 0;
}
```

***

## 2-2

这道题的思路就是尽可能的往后跳

```
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
```

