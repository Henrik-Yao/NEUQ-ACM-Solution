#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[100000],a1[100000],a2[100000];
	int i1,i2,i;
	i1=i2=i=0;
	while(1)
	if(!(cin>>a[i++])) break;
	sort(a,a+i-1);
    for(int j=0;j<i-1;j++){
	    cout<<a[j];
	    if(j<i-2)cout<<"->";
    }
	cout<<endl;
	for(int j=0;j<i-1;j++){
		if(a[j]%2)a1[i1++]=a[j];
		else a2[i2++]=a[j];
	}
	for(int j=0;j<i1;j++){
		cout<<a1[j];
		if(j<i1-1)cout<<"->";
	}
	cout<<endl;
	for(int j=0;j<i2;j++){
		cout<<a2[j];
		if(j<i2-1)cout<<"->";
	}
	return 0;
}
