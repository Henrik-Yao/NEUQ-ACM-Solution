#include <iostream>
#include <map>
#include <set>
using namespace std;

set<int>s;
map<int,int>m;
int n;
int main(){
	cin>>n;
    for(int i = 0;i < n;i++){
        int data;
        cin>>data;
        s.insert(data);
        m[data]++;
}
    for(set<int>::iterator i = s.begin();i != s.end();i++){
    cout<<*i<<':'<<m[*i]<<endl;
}
	return 0;
}