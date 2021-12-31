#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string s){
for(int i=0,j=s.length()-1;i<=j;i++,j--)
if(s[i]!=s[j]) return false;
return true;
}
int main(void){
string str;
cin >> str;
cout  << (isPalindrome(str) ? "Yes" : "No") << endl;
return 0;
}
