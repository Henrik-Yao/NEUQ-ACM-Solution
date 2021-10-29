#include <iostream>
using namespace std;
int main(){
    int T,n1,n2;
    cin >> T;
    for(int abc=1;abc<=T;abc++){
        cin >> n1;
        int a[n1];
        for(int i=0;i<n1;i++) cin >> a[i];
        cin >> n2;
        int b[n2];
        for(int i=0;i<n2;i++) cin >> b[i];
        int sum[n1+n2];
        int i=0,j=0,k=0;
        while(i<n1&&j<n2){
            if(a[i]<b[j]){
                sum[k]=a[i];
                k++;
                i++;
            }
            else{
                sum[k]=b[j];
                k++;
                j++;
            }
        }
        while(i<n1) {sum[k]=a[i];k++;i++;}
        while(j<n2) {sum[k]=b[j];k++;j++;}
        cout << sum[0];
        for(int i=1;i<n1+n2;i++) cout << " " << sum[i];
        cout << endl;
    }
    return 0;
}
