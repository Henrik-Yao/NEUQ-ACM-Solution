#include<iostream>
using namespace std;

long long a[100100]={0},n;

void Sort(int l, int r){
	int i,j,t,temp;
	if(l>=r) return;
	
	temp = a[l];
	i = l;
	j = r;
	while(i!=j){
		while(a[j]>temp && i<j){
			j--;
		}
		while(a[i]<=temp && i<j){
			i++;
		}
		if(i<j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	
	a[l] = a[i];
	a[i] = temp;
	for(int k=1; k<=n; k++){
		printf("%d ",a[k]);
	}
	cout << endl;
	Sort(l,i-1);
	Sort(i+1,r);
	
	return;
}

int main(){
	int i,j,t;
	scanf("%d",&n);
	
	for(i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	
	Sort(1,n);
	
	for(i=1; i<=n; i++){
		printf("%d ",a[i]);
	}
	
	return 0;
} 

/*
5
4 5 3 2 1
*/
