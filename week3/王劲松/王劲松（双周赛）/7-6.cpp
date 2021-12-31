#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1;
	cin>>s1;
	int i,n=s1.size();
	sort(s1.begin(),s1.end());
	for(i=0;i<n;i++){
			if(i<n-1){
				cout<<s1[i];
			}
			else cout<<s1[i]<<endl;
		}
	while(next_permutation(s1.begin(),s1.end())){
		for(i=0;i<n;i++){
			if(i<n-1){
				cout<<s1[i];
			}
			else cout<<s1[i]<<endl;
		}
	}
	return 0;	
}
