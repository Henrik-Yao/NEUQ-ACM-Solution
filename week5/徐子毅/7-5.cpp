#include <iostream>
using namespace std;
int vis[50005];
int m[50005];
int n;
bool getout=false;
bool deadloop=false;
void jump(int p){
    if(vis[p]==1||p<0||p>=n) return;
	vis[p]=1;
    if(m[p]==0||getout==true){getout=true;return;}
    else{
        if(p+m[p]>=0&&p+m[p]<n) jump(p+m[p]);
        if(p-m[p]>=0&&p-m[p]<n) jump(p-m[p]);
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> m[i];
    int start;
    vis[start]=1;
    cin >> start;
    jump(start);
    if(getout==true) cout << "True";
    else if(getout==false) cout << "False";
}