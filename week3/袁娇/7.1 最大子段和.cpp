#include <iostream>
using namespace std;
int main()
{
    int n, maxSum=0, nowSum=0;
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        nowSum+=num;
        if(nowSum>maxSum)maxSum=nowSum;
        else if(nowSum<0)nowSum=0;

    }

    cout<<maxSum<<endl;
    return 0;
}
