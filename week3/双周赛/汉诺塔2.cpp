#include <iostream>
using namespace std;
 
int main()
{
	int n;
	double a[65],b[65]; 
	a[1]=1;
	for(int i=2; i<=64; i++) 
		a[i] = 2*a[i-1]+1;
	b[1]=1;
	b[2]=3;
	for(int i=3; i<=64; i++){
		double min = a[i],flag;
		for(int j=1; j<i; j++){
			flag = 2*b[j]+a[i-j]; 
			if(min > flag) 
				min = flag;
		}
		b[i] = min;
	}
	while(scanf("%d",&n)!=EOF){
		cout << b[n] << endl;
	} 
	return 0;
}
