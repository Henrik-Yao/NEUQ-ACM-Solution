#include<iostream>
using namespace std;
extern int sum=0;
 
int BinarySearch(int a[],const int &x,int n)
{
    unsigned long long left = 0;
    unsigned long long right = n-1;
    while (left <= right)
    {
        sum++;
        unsigned long long middle = (left + right)/2;
        if(x == a[middle]) return middle;
        if(x > a[middle]) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
} 
 
unsigned long long main()
{
    unsigned long long n,a[1000],x,result;
    cin>>n;
    for(unsigned long long i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    
    result = BinarySearch(a,x,n);
    cout<<result<<endl<<sum;
    return 0;
 
}
 
