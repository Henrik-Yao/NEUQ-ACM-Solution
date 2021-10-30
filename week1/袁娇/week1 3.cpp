#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double R,d,n;
	cin>>R>>d>>n;
	n=fabs(n);
    if(4 * R * R <= d * d + n * n)
	if(n>R)
	printf("%.2f",2.0*sqrt(d*d+(n-R)*(n-R))-R);
	else printf("%.2f",2*d-R);
	return 0;
	
}
