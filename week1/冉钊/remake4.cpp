#include<bits/stdc++.h>
using namespace std;
int way=1;
int devide(int n){
	
	if(n>1){
		for(int i=1;i<n/2+1;i++){
			if(n%i==0){
				way++;
				devide(i);
			}
			
		}
		
	}
	else;
	return way;
}
int main(){
	int n;
	cin>>n;
	printf("%d",devide(n));
	
	
	
	return 0;
}

