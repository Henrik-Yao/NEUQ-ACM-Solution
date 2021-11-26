#include <iostream>
#include <cstring>
using namespace std;
int dp[1005],a[1005];
int main(){
	int T;
	cin >> T;
	for(int abc=1;abc<=T;abc++){
	    int n;
		int _max=1;
	    cin >> n;
		for(int i=0;i<n;i++) {cin >> a[i];dp[i]=1;}
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
		        if(a[i]>a[j]) {dp[i]=max(dp[i],dp[j]+1);}
       		}
   		}
        for(int i=0;i<n;i++){
            if(dp[i]>_max) _max=dp[i];
        }
		cout << _max << endl;
        if(abc!=T) cout << endl;
	}
}