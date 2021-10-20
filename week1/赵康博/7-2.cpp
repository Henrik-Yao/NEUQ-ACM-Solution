#include <iostream>

using namespace std;

int *s = (int *) malloc(1000001*sizeof(int));
int main(){
    int n;
    cin>>n;
    int *f = (int *) malloc(n*sizeof(int));
    int sum = 1;
    int cun1[n],cun2[n];
    for (int i = 0; i < n; ++i) {
        cin>>f[i];
        //cout<<f[i];
        if(i==0){
            cun1[i] = 1;
            s[f[i]] = 1;
        }
        else if(s[f[i]]!=1){
            cun1[i] = cun1[i - 1] + 1;
            s[f[i]] = 1;
        }
        else cun1[i] = cun1 [i-1];
    }
    for (int i = 0; i < n; ++i) {
        if(i==0){
            cun2[i] = 1;
            s[f[n-i-1]] = 2;
        }
        else if(s[f[n-i-1]]!=2){
            cun2[i] = cun2[i-1] + 1;
            s[f[n-i-1]] = 2;
        } else cun2[i] = cun2[i-1];
    }
    for (int i = 0; i < n-1; ++i) {
        sum = max(cun1[i] + cun2[n-i-2],sum);
    }
    cout<<sum;

    return 0;
}