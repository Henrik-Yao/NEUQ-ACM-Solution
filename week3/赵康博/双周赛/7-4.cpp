#include <iostream>
#include <cmath>
using namespace std;

double f(int n){
    return pow(2,n)-1;
}
int main() {
    int n;
    double s[65];
    while (cin>>n){
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if(j==0)s[i] = f(i);
                s[i] = min(s[i],2*s[j]+f(i-j));
            }
        }
        cout<<s[n]<<endl;
    }
    return 0;
}