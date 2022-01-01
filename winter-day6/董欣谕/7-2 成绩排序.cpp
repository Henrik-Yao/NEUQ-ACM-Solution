#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct person{
	int score;
	string name;
}p[21];
bool cmp(person a,person b){
	if (a.score!=b.score) return a.score>b.score;
	else return a.name<b.name;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>p[i].name>>p[i].score;
	sort(p+1,p+1+n,cmp);
	for (int i=1;i<=n;i++){
		cout<<p[i].name<<" "<<p[i].score;
        if (i!=n) cout<<endl;
    }
	return 0;
} 
