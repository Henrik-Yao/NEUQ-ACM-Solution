#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int R,d,n;
    float dis;
    cin>>R>>d>>n;   
    if (fabs(n)<=R)
    {
        dis=2*fabs(d)-R;
    }
    else
    {
        dis=sqrt((fabs(n)-R)*(fabs(n)-R)+d*d)*2-R;
    }
    printf("%.2lf",dis);
    return 0;
}
