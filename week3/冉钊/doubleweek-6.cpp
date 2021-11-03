#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string a;
    cin>>a;
    sort(a.begin(),a.end());
    do{
        cout<<a<<endl;
    }while(next_permutation(a.begin(),a.end()));

    return 0;
}