#include<bits/stdc++.h>
using namespace std;
   queue<int> q[100]; 
int main() {
    int ans=0; 
    int n;
    cin >> n;
    for(int i=0; i < n; i++) {
        int x;
        cin >> x; 
        bool flag = false;
        for(int j=0; j < ans; j++) { 
            if(q[j].back() > x) { 
                q[j].push(x);
                flag = true;
                break;
            }
        }
        if(!flag) { 
            q[ans].push(x);
            ans++;
        }
    }
    for(int i=0; i < ans; i++) { 
        if(q[i].back() == 1) {
            while(!q[i].empty()) { 
                cout << q[i].front();
                q[i].pop();
                if(!q[i].empty()) cout << ' '; 
                else cout << endl;
            }
            break;
        }
    }
    cout << ans << endl; 
    return 0;
}

