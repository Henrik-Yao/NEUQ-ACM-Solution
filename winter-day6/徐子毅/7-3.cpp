#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[55];
int main(){
    int N;
    cin >> N;
    memset(a,0,sizeof a);
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        a[num]++;
    }
    for(int i=0;i<=50;i++){
        if(a[i]!=0) cout << i << ":" << a[i] << endl;
    }
    return 0;
}