#include <bits/stdc++.h>
using namespace std;
struct TIME{
    int start;
    int end;
};
bool cmp(TIME p1,TIME p2){
	return (p1.end<p2.end);
}
void sum(){
    int n;
    cin>>n;
    vector<TIME>N(n);
    for(int i=0;i<n;i++)
    {
    cin>>N[i].start>>N[i].end;
    }
    sort(N.begin(),N.end(),cmp);
    int END=N[0].end;
    int cnt=1;
    for(int i=1;i<n;i++){
    if(N[i].start>=END){
    cnt++;
    END=N[i].end;
    }
    }
    cout<<n-cnt<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        sum();
    }
    return 0;
}
