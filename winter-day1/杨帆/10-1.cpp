#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+10;
ll a[N];

int lowbit(int x){
    return x & (-x);
}

void update(int site,int x,int n){
    for(int i=site; i<=n; i+=lowbit(i)){
        a[i] += x;
    }
}

ll get_sum(int site){
    ll sum = 0;
    for(int i=site; i>0; i-=lowbit(i)){
        sum += a[i];
    }
    return sum;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        update(i,x,n);
    }
    while(m--){
    	int x,y,z;
        cin >> x >> y >> z;
        if(x == 1){
            update(y,z,n);
        }
        else if(x == 2){
            cout << get_sum(z) - get_sum(y-1) << endl;
        }
    }
    return 0;
}
