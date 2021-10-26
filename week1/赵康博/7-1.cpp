#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s[50000];
    int n;
    cin>>n>>s;
    char f[20];
    int t = 0,sum = 0;
    for (int i = 0; i < n; ++i) {
        cin>>f;
        for (int j = 0; j < strlen(s); ++j) {
            for (int k = 0; k < strlen(f); ++k) {
                if(s[j+k]!=f[k]){
                    t = 1;
                    break;
                }
            }
            if(t==0){
                sum++;
            }
            t = 0;
        }
        cout<<sum<<endl;
        sum = 0;
    }
    return 0;
}