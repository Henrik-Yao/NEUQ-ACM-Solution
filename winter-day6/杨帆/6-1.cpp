#include<bits/stdc++.h>
using namespace std;
int a[1000005];

int main(){
    int n;
    while(cin >> n){
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=1; i<n; i++){
            int temp = a[i],j;
            for(j=i-1; j>=0 && a[j] > temp; j--){
                a[j+1] = a[j];
            }
            a[j+1] = temp;
            for(int j=0; j<n; j++){
                if(j == n-1){
                    cout << a[j] << endl;
                }
                else{
                    cout << a[j] << " ";
                }
            }
        }
    }
    
}
