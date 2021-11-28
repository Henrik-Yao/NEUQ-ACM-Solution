#include <bits/stdc++.h>
using namespace std;
const int N = 233333;
int n,top,num[N];
string a,sta[N];
int main() {
    getline(cin,a);
    n = a.size();
    sta[0]="";
    for (int i=0; i<n; ) {
    	if (a[i]=='[') {
    		sta[++top]="";
    		i++;
    		num[top] = 0;
    		while(isdigit(a[i])) num[top] = num[top]*10+a[i]-48, i++;
		} else if (a[i]==']') {
			int end = num[top];
			while(end--) sta[top-1]+=sta[top];
			top--;
			i++;
		} else {
			sta[top] += a[i];
			i++;
		}
	}
	cout<<sta[0]<<endl;
    return 0;
}
