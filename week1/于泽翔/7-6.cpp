#include <iostream>
using namespace std;
int main(void)
{
	long long int n, T, v, t, max;
    int b=1;
    cin>>n>>T;
    while(n--)
    {
        long long joy;
        cin>>v>>t;
        if(t<=T)
            joy=v;
        else
            joy=v-t+T;
        if(b)
        {
            max=joy;
            b--;
        }
        if(joy>max)
            max=joy;
    }
    cout<<max;
    
	return 0;
}