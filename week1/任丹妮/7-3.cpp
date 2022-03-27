#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int R,d,n;
    cin>>R>>d>>n;
    double s;
    if(abs(n)>R){
        s=2*sqrt((abs(n)-R)*(abs(n)-R)+d*d)-R;
    }
    else s=2*abs(d)-R;
    printf("%.2lf",s);
    return 0;
}
