#include <bits/stdc++.h>
using namespace std;

char str[10],temp[10];
int main() {
	cin>>str;
	int len=strlen(str);
    sort(str,str+len);
    do {
		cout<<str<<endl;
	} while (next_permutation(str,str+len));
	return 0;
}
