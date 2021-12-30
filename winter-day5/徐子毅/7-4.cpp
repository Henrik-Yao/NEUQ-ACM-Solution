#include<iostream>
using namespace std;
int a[1005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int target,result=-1,times=0;
    cin>>target;
    int left = 0,right = n-1;
    while (left<=right){
        times++;
        int middle = (left+right)/2;
        if(target == a[middle]) {result=middle;break;}
        else if(target > a[middle]) left=middle + 1;
        else right=middle - 1;
    }
    cout<<result<<endl<<times<<endl;
    return 0;
}