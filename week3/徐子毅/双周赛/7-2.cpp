#include <iostream>
#include <cstring>
using namespace std;
void Hanoi(int n,string a,string b,string c){
    if(n==1) {cout << a << "->" << c << endl;return;}
    else {
        Hanoi(n-1,a,c,b);
        cout << a << "->" << c << endl;
        Hanoi(n-1,b,a,c);
    }
}
int main(){
    int n;string a,b,c;
    cin >> n >> a >> b >> c;
    Hanoi(n,a,b,c);
    return 0;
}
