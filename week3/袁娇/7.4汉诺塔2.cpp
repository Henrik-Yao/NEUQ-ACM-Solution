#include<iostream>
using namespace std;
#include"math.h"
#define Inf 0x7fffffff
int main()
{
    int n,i,j,min,x[66]={0,1,3};;
    for(i=3;i<66;i++)
    {
        min=Inf;
        for(j=1;j<i;j++)
        {
            if(min>2*x[j]+pow(2.0,1.0*i-j)-1)  
                min=2*x[j]+pow(2.0,1.0*i-j)-1; 
        }
        x[i]=min;
    }
    while(cin>>n)
    {
        cout<<x[n]<<endl;
    }
    return 0;
}
