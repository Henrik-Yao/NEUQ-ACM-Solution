#include <iostream>
using namespace std;
unsigned long long array[55];
int main(){
	int n;
	array[1]=1;
	array[2]=2;
	array[3]=4;
	for(int i=4;i<=50;i++){
		array[i]=array[i-1]+array[i-2]+array[i-3];
	}
	while(cin >> n) cout << array[n] << endl;
	return 0;
}
