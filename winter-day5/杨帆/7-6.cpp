#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int a[N],ans[N];

int BS(int n,int m,int a[],int aim);

int main(){
    int n,m;
    while(cin >> n){
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1; i<=n; i++){
            if(i != n){
                cout << a[i] << " ";
            }
            else{
                cout << a[i] << endl;
            }
        }
        cin >> m;
        for(int i=1; i<=m; i++){
            int temp;
            cin >> temp;
            ans[i] = BS(n,m,a,temp);
        }
        for(int i=1; i<=m; i++){
            if(i != m){
                cout << ans[i] << " ";
            }
            else{
                cout << ans[i] << endl;
            }
        }
    }
    return 0;
}

int BS(int n,int m,int a[],int aim){
    int left = 1,right = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == aim){
            return mid;
        }
        else if(a[mid] < aim){
            left = mid + 1;
        }
        else if(a[mid] > aim){
            right = mid - 1;
        }
    }
    return 0;
}

