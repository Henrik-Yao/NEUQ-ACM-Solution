#include<bits/stdc++.h>
using namespace std;
int a[1001],N;

void print(int *a);
void quick_sort(int l,int r);

int main(){
	int i;
	cin >> N;
	for(i=1;i<=N;i++){
        cin >> a[i];
    }
	quick_sort(1,N);
	print(a);
	return 0;
}

void quick_sort(int l,int r){
	if(l>=r) return;
	else{
		int i=l;
		int j=r;
		int t=a[l];
		while(i<j){
		    while(i<j&&a[j]>t)
			    j--;
		    while(i<j&&a[i]<=t)
			    i++;
		    swap(a[i],a[j]);
	    }
	    swap(a[i],a[l]);
	    print(a);
	    quick_sort(l,i-1);
	    quick_sort(i+1,r);
	}
}

void print(int *a){
	for(int i=1;i<=N;i++)
		printf("%d ",a[i]);
	cout<<endl;
}
