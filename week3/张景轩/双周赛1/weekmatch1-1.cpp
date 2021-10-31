#include<iostream>
using namespace std;
int arr[10001];
int maxsec=0;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int j=0;j<n;j++)
    {
        arr[j] =max(max(arr[j],0),arr[j-1]+arr[j]);
        maxsec = max(arr[j],maxsec); 
    }

    cout<<maxsec;
    return 0;  
}


//递归，得到数组的索引，分别球其左右和中间值三种最大字段和
//输出最大值