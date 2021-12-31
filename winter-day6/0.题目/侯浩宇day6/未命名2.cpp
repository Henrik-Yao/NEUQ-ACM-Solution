#include<bits/stdc++.h>
using namespace std;
struct student{
	char name[10];
	int c;
}; 
int main(){
	struct student students[50];
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>students[i].name>>students[i].c;
	}
	int max;
	for (max=0;max<n-1;max++){
	for (int i=max+1;i<n;i++){
		if (students[max].c<students[i].c){
			swap(students[i],students[max]);
		}

	}
	}
	for (max=0;max<n-1;max++){
	for (int i=max+1;i<n;i++){
		if(students[max].c==students[i].c){
			if(students[max].name<students[i].name)
			swap(students[i],students[max]);
		}
	}
	}
	for (int i=0;i<n;i++){
		printf("%s %d",students[i].name,students[i].c);
		if(i!=n-1){
			cout<<endl;
		}
	}
	return 0;
} 
