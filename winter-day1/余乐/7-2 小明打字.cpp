#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#define N 50001
using namespace std;
char a[N];
int p,flag,lena;
vector<char> q;
int main(){
	char ch;
	while(scanf("%c",&ch) && ch != '\n'){
        a[lena ++] = ch;
	}
	for(int i = 0;i < lena;i ++){
		char b = a[i];
		if(b == '[') p = 0;
		else if(b == ']') p = q.size();
		else if(b == '{') p = max(0 , p - 1);
		else if(b == '}') p = min((int)q.size() , p + 1);
		else if(b == '-') flag ^= 1;
		else if(b == '='){
			if(q.size()){
				q.erase(q.begin() + p - 1);
				p --;
			}
		}
		else {
			if(p == q.size() - 1) q.push_back(a[i]);
			else if(flag) q[p] = a[i];
			else q.insert(q.begin() + p , a[i]);
			p ++;
		}
	}
	for(int i = 0;i < q.size();i ++) printf("%c",q[i]);
	printf("\n");
	return 0;
}
