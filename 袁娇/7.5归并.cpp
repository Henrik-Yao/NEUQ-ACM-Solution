#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int a[N],temp[N];
void sort(int l,int r);
int main(){
    cin>>n;int b,v;
    for(int i = 0; i < n; i++){
    	cin>>b;
    for(int i=0;i<b;i++){
    		cin>>a[i];
			}cin>>v;
		for(int i=b;i<b+v;i++){
				cin>>a[i];
			}
		
    
    sort(0,b+v-1);
    for(int i = 0; i < b+v-1; i++)
       cout<<a[i]<<" ";cout<<a[b+v-1];cout<<endl;
       
}}

void sort(int l, int r){
    if(l >= r)  return;
    int mid =( l + r)/2;
    sort(l, mid);
    sort(mid + 1, r);
    int k = 0; 
    int i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
       
        if(a[i] < a[j])
		 temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) 
	temp[k++] = a[i++];
    while(j <= r)
	 temp[k++] = a[j++];
    for(i = l, j = 0; i <= r; i++,j++)
    a[i] = temp[j];
}

