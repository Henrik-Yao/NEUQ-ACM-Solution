#include<bits/stdc++.h>
using namespace std;
int t,n;
struct ss{
    int beginn;
    int endd;
}number[101];
bool px(ss a,ss b){
	return a.endd<b.endd;
}
void anss(){
	
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>number[i].beginn>>number[i].endd;
	sort(number,number+n,px);
	int ans=1;
	int j=0;
	for(int i=0;i<n;i++){
		if(number[i].beginn>=number[j].endd){
			j=i;
			ans++;
		}
	}
	cout<<n-ans<<endl;
} 
int main(){
	cin>>t;
	while(t--){
		anss();
	} 
	return 0;
}
