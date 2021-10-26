#include<iostream>
#include<set>
using namespace std;
int b[1000001]={0} ,power1[1000001],power2[1000001],power;

int main() {
	int n,max=0;
    set<int>s1,s2;
	scanf("%d",&n);
	int a[n];
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);

	}
	for(int i=0; i<n; i++) {
		s1.insert(a[i]);
		power1[i]=s1.size();

	}
	for(int i=n-1;i>=0;i--){
		
		power2[i]=s2.size();
		s2.insert(a[i]);
		
		
		
	}
	for(int i=0;i<n;i++){
		power=power1[i]+power2[i];
		if(power>max)max=power;
	}
	
	
	cout<<max;
	return 0;
}
