#include <iostream>
using namespace std;
void Merge(int ma[],int L,int M,int R){
	int leftsize=M-L;
	int rightsize=R-M+1;
	int leftarray[leftsize],rightarray[rightsize];
	int i;
	for(i=L;i<M;i++) {
		leftarray[i-L]=ma[i];
	}
	for(i=M;i<=R;i++) {
		rightarray[i-M]=ma[i];
	}
	int k=L,j=0;i=0;
	while(i<leftsize&&j<rightsize){
		if(leftarray[i]<rightarray[j]) {
			ma[k]=leftarray[i];k++;i++;
		}else {
			ma[k]=rightarray[j];k++;j++;
		}
	}
	while(i<leftsize){ma[k]=leftarray[i];i++;k++;}
	while(j<rightsize){ma[k]=rightarray[j];j++;k++;}
}
void Mergesort(int m[],int L,int R){
	if(L==R) return;
	else{
		int mid=(R+L)/2;
		Mergesort(m,L,mid);
		Mergesort(m,mid+1,R);
		Merge(m,L,mid+1,R);
	}
}
int main(){
	int T,nu;
	cin >> T;
	int a[T];
	for(int abc=0;abc<T;abc++){cin >> nu;a[abc]=nu;}
	Mergesort(a,0,T-1);
	for(int abc=0;abc<T;abc++){cout << a[abc] << " ";}
	cout << endl;
	return 0;
}
