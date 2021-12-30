#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1005];
int main(){
    int n;
    while(cin>>n){
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        cout << a[0];
        for(int i=1;i<n;i++) cout << " " << a[i];
        cout << endl;
        
        int T;
        cin >> T;
        for(int j=0;j<T;j++){
            int target,result=-1,times=0;
            cin>>target;
            int left = 0,right = n-1;
            while (left<=right){
              int middle = (left+right)/2;
              if(target == a[middle]) {result=middle;break;}
              else if(target > a[middle]) left=middle + 1;
              else right=middle - 1;
           }
            if(j==0) cout << result+1;
            else cout << " " << result+1;
        }
        cout << endl;
    }
    return 0;
}