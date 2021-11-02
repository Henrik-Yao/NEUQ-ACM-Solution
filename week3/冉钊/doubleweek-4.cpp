#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=65;
long long a[N]={0};
double hannuota(int n){
   return pow(2,n)-1;
}
int main(){
     int n;
for(int i=1;i<=64;i++){
     long long m=1e8;
     for(int j=0;j<i;j++){
        if(2*a[j]+hannuota(i-j)<m){
           m=2*a[j]+hannuota(i-j);
           }
           else;
           } //利用初始数据往后一位求，不断储存；
     a[i]=m;
}
     while(cin>>n){
        cout<<a[n]<<endl;
     }

   return 0;
}