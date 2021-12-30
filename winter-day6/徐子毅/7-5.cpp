#include<iostream>
using namespace std;
int n;
void sort(int a[], int n,int point)
{
    int left = 2*point+1;
    int right = 2*point+2;
    int maxp=point;
    if(left<n && a[left] > a[maxp]) maxp = left;
    if(right<n && a[right] > a[maxp]) maxp = right;
    if(maxp!=point){
        swap(a[maxp],a[point]);
        sort(a,n,maxp);
    }
}
int main(){
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=n/2-1;i>= 0;i--) sort(a,n,i);
    for(int i=n-1;i>=1;i--){
        for(int i=0;i<n;i++) cout << a[i] << " ";
        cout << endl;
        swap(a[0],a[i]);
        sort(a,i,0);
    }
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}