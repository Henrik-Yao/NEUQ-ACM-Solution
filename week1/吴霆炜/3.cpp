#include <bits/stdc++.h>
using namespace std;

int main(){
    double R,d,n;
    cin>>R>>d>>n;
    n = fabs(n);
    d = fabs(d);
    double sum;
    if(n > R)
    sum = 2 * sqrt(pow(d,2) + pow((n - R),2)) - R;
    else 
    sum = 2 * d - R;
    cout<<fixed<<setprecision(2)<<sum<<endl;
    return 0;
}