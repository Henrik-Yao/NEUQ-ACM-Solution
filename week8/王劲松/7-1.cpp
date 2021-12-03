#include<iostream>
using namespace std;
int f();
int findm(int i);
int main(){
    int n;
    cin>>n;
    while(n--){
        cout<<f()<<endl;
    }
    return 0;
}
int f(){
    int t,i=0;
    cin>>t;
    int ks[t],js[t];
    while(i<t){
        cin>>ks[i]>>js[i];
        i++;
    }
    int j,cnt=0;
    for(i=0;i<t-1;cnt++){
        int mini=js[i],minjs=25;
        if(cnt==0)mini=0;
        for(j=0;j<t;j++){
            if(ks[j]>=mini){
                if(minjs>js[j]){
                    i=j;
                    minjs=js[j];
                }
            }
        }//cout<<i<<"  "<<minjs<<endl;
        if(minjs==25)break;
    }
    return t-cnt;
}
