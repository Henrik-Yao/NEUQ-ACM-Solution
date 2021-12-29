#include<bits/stdc++.h>
using namespace std;
#define N 2000010
int main()
{
    int n;
    while (cin>>n) {
        int f[N];
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
        sort(f, f + n);
        for (int i = 0; i < n; i++) {
            if(i!=0)cout<<" "<<f[i];
            else cout<<f[i];
        }
        cout<<endl;
        int m;
        cin>>m;
        int tt = 0;
        for(int i = 0; i < m; i++){
            int x;
            cin>>x;
            int num = 0;
            int l = 0;
            int r = n - 1;
            while (l <= r)
            {
                int mid = (l+r)/2;
                if(f[mid] == x)
                {
                    num = mid + 1;
                    break;
                }
                else if(f[mid] > x){
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            if(tt == 0){
             cout<<num;
             tt++;
            } else cout<<" "<<num;
        }
        cout<<endl;
    }
    return 0;
}
