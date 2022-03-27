#include <iostream>
#include <cmath>
using namespace std;
int ju(int n) {
    if(!(n%2)) return 2;
    int vis = 1;
    for (int i = 2; i <= sqrt(n+1)+1; i++) {
        if(!(n%i)) {
            vis = 0;
            break;
        }
    }
    if(vis) return 1;
    vis = 1;
    for (int i = 2; i <= sqrt(n-2)+1; i++) {
        if(!((n-2)%i)) {
            // printf("i = %d\n", i);
            vis = 0;
            break;
        }
    }
    if(vis) return 2; 
    else return 3;
}
int main (){
    int k, n;
    cin >> k;
    while(k--) {
        cin >> n;
        cout << ju(n) << endl;
    }


    return 0;
}
