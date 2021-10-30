#include<bits/stdc++.h>
using namespace std;

double a,b,c;
int t;
int main()
{ 
  	cin>>c>>a>>b;
  	b=fabs(b);
  	if (b>=c) printf("%.2lf",2.0*sqrt(a*a+(b-c)*(b-c))-c);
  	else printf("%.2lf",2*a - c);
  return 0;  
}
