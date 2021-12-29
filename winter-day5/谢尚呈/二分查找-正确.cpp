#include<iostream>
using namespace std;

int sum=0;
int list[1000];
 
int search(int x, int n)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        sum++;
        int middle=(left+right)/2;
        if(x==list[middle]) return middle;
        if(x>list[middle]) left=middle+1;
        else right=middle-1;
    }
    return -1;
} 
 
int main()
{
    int n,x;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>list[i];
    cin>>x;
    
    int result=search(x, n);
    cout<<result<<endl<<sum;
    return 0;
 
}
