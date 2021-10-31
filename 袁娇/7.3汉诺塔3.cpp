#include<iostream>
using namespace std;
 
int main()
{
    int n;
    while(cin>>n)
        {
        long long int step=1;
        for(int i=1;i<=n;i++)
            step*=3;
            step-=1;
        cout<<step<<endl;
    }
    return 0;
}
