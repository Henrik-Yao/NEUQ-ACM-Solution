#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int r,d,n;
	scanf("%d %d %d",&r,&d,&n);
	d=fabs(d);
	n=fabs(n);
	double re;
	if(n>r) re=2.0*sqrt(pow(d,2)+pow(n-r,2))-r;
	else re=2*d-r;
	printf("%.2lf",re);
	return 0;
}
