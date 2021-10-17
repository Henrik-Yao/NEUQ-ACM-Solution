#include <iostream>
#include <cmath>
using namespace std;
double distant(double x,double y,double a,double b){
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
int main(){
    double R,d,n,S,min=9999;
    int flag=0;
    cin >> R >> d >> n;
    double l1,l2;
    for(double i=d-R;i<d+R;i=i+0.01){
        for(double j=n-R;j<n+R;j=j+0.01){
            if(distant(i,j,d,n)<=R){
				S=distant(i,j,0,0)+distant(i,j,2*d,0)-R;
//				cout << S <<endl;
				if(flag==0) {
					min=S;
					flag=1;
				}
            }
            if(S<min) min=S;
        }
    }
    printf("%.2lf",min);
    return 0;
}
