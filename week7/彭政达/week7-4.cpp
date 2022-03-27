#include <bits/stdc++.h>
using namespace std;
vector<int>m,n;
int main (){
	int t,k;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>k;
		for(int i=0;i<k;i++){
			int num;cin>>num;
			m.push_back(num);
			n.push_back(1);
   		}
   		int sum=0;
		for(int i=0;i<k;i++){
			for(int j=0;j<i;j++)
				if(m[i]>m[j]) n[i]=max(n[i],n[j]+1);
			sum=max(sum,n[i]);
   		}
   		cout<<sum<<endl;
 	}
  	return 0; 
}
