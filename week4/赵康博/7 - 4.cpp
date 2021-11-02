#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin>>n;
    ll a,b,c;
    ll sum = 1;
    for (int i = 0; i < n; ++i) {
        cin>>a>>b>>c;
        while (b){
            if(b%2==1){
                sum = sum*a%c;
            }
            b = b / 2;
            a = a * a%c;
        }
        cout<<sum<<endl;
        sum = 1;
    }
    return 0;
}