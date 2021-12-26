#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int N,M,K;
	cin >> N >> M >> K;
	int a[1100]={0};
	int i=1,sum=0,book=0,flag;
	flag = 0;
	while(1){
		if(a[i] == 0){
			book++;
			if((flag == 0 && book == M)||(flag == 1 && book == K)){
				cout << i << " ";
				a[i] = 1;
				sum++;
				flag ^= 1;
				book = 1;
			}
		}
		if(sum == N) break;
			if(flag == 0) i--;
			else i++;
			if(i<=0) i=N;
			if(i>N) i=1;
		
	}
	
	
	
	
	return 0;
}
