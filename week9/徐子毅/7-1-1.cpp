#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ine[100005];
vector<int> cracks;
void breakline(int start,int end){
    int crack_num=0;
    int line_num=1;
    bool is_ine=true;
    for(int i=start+1;i<=end;i++){
        if(ine[i]==0&&ine[i-1]==1){
            line_num++;
            is_ine=false;
        }else if(ine[i]==1&&ine[i-1]==0){
            cracks.push_back(crack_num);
            crack_num=0;
            is_ine=true;
        }
        if(!is_ine) crack_num++;
    }
    return ;//line_num;
}
int main(){
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    if(a[0]<0) {
        int move=a[0];
        for(int i=0;i<n;i++) a[i]-=move;
    }
    for(int i=0;i<n;i++) ine[a[i]]=1;
    breakline(a[0],a[n-1]);
    sort(cracks.begin(),cracks.end());
    int min_length=n;
    for(int T=0;T<cracks.size()-m+1;T++){
        min_length+=cracks[T];
    }
    cout << min_length << endl;
}
