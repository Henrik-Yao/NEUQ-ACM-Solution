#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,R,d,n;
	double dis;
	cin>>R>>d>>n;
	if(abs(n)>R)
	{ 
	    t=abs(n)-R;
	    dis=sqrt(t*t+d*d);
	    dis=dis*2-R;
        printf("%.2lf",dis);
    } 
	else 
	{
		dis=2*abs(d)-R;
		printf("%.2lf",dis);
	 } 
}

