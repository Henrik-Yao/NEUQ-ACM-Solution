#include <iostream>
using namespace std;
int Find(int a[],int front,int end){
    if(front==end) return a[front];
    else{
        int mid=(front+end)/2;
        int leftnnumax=Find(a,front,mid);
        int rightnnumax=Find(a,mid+1,end);
        int ma=max(leftnnumax,rightnnumax);
        //Middle
        int leftnumber=0;int leftmax=0;int rightnumber=0;int rightmax=0;
        for(int i=mid;i>=front;i--){
            leftnumber+=a[i];
            leftmax=max(leftmax,leftnumber);
        }
        for(int i=mid+1;i<=end;i++){
            rightnumber+=a[i];
            rightmax=max(rightmax,rightnumber);
        }
        ma=max(ma,leftmax+rightmax);
        return ma;
    }
}
int main(){
    int T;
    cin >> T;
    int a[T];
    for(int i=0;i<T;i++){
        cin >> a[i];
    }
    cout << Find(a,0,T-1) << endl;
    return 0;
}
