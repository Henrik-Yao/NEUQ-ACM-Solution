#include<bits/stdc++.h>
using namespace std;

struct List{
	string name;
	int grade;
};

bool compare(const List &a, const List &b){
	if(a.grade == b.grade)
		return (a.name < b.name);
	else return a.grade > b.grade;
}

int main(){
	int n;
	List a[30];
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i].name >> a[i].grade;
	}
	sort(a,a+n,compare);
	for(int i=0; i<n; i++){
		cout << a[i].name << " " << a[i].grade << endl;
	}
	
	return 0;
}
