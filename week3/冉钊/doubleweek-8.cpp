#include<iostream>
using namespace std;
int lower_bound(int a[],int left,int right,int goal){
       int m,n=right+2;
       while(left<right){
           m=left+(right-left)/2;
           if(a[m]>=goal) right=m;
           else left=m+1;
       }
     if(a[left]>=goal) return left+1;
     else return n;
}
int main (){
     int n,goal;
     cin>>n>>goal;
     int a[n];
     for(int i=0;i<n;i++)
     cin>>a[i];

     cout<<lower_bound(a,0,n-1,goal)<<endl;


    return 0;
}