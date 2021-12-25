# include<bits/stdc++.h>
using namespace std;
struct P{
    int begin;
    int end;
};
bool cmp(P p1,P p2){
	return(p1.end<p2.end);
}
int main(){
    int n;
    int T;
    cin>>T;
    while(T--){
    cin>>n;
    struct P a[1000000];
    for(int i=0;i<n;i++){
        cin>>a[i].begin>>a[i].end;
     }
        sort(a,a+n,cmp);
        int index=0;
        int count=1;
        for(int i=1;i<n;i++){
            if(a[i].begin>=a[index].end)index=i;
            else count++;
        }
        cout<<count-1<<endl;
    }
    return 0;
}
