#include<iostream>
using namespace std;

int f(int n,int flag){
	int i;
	for(i=2; i<n; i++){
		if(n%i == 0){
			flag++;
			flag = f(n/i,flag);
		}
	}
	return flag;
}

int main(){
	int n,i=2,flag=1,count,a;
	cin >> n;
	a = f(n,flag);
	count = a*2;
	cout << count;
	
	return 0;
}
