#include<iostream>
#include<cstring>
using namespace std;

void hanoi(int n, string x, string y, string z){
	if(n == 1) 
		cout  << x << "->" << z << endl;
	else{
		hanoi(n-1, x, z, y);
		cout << x << "->" << z << endl;
		hanoi(n-1, y, x, z);
	}
}

int main(){
	int n; 
	string x,y,z;
	cin >> n >> x >> y >> z;
	hanoi(n,x,y,z);
	
	return 0;
} 
