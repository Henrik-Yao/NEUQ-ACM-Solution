#include <bits/stdc++.h>
using namespace std;
int main(){
	char num[9];
	cin>>num;
	int n=strlen(num);
	sort(num,num+n);
	do{
		for(int i=0;i<n;i++){
			cout<<num[i];
		}
		cout<<endl;
	}while(next_permutation(num,num+n));
	
	
	
	
	return 0;
}
