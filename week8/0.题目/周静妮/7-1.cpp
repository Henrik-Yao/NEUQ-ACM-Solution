#include<bits/stdc++.h>
using namespace std;
struct Program{
	int start,end;
};
bool cmp(Program p1,Program p2){
	return(p1.end<p2.end);
}
void run(){
	int n;
	cin>>n;
	vector<Program>ps(n);
	for(int i=0;i<n;i++){
		cin>>ps[i].start>>ps[i].end;
		
	}
	sort(ps.begin(),ps.end(),cmp);
	int cnt=1;
	int curEnd=ps[0].end;
	for(int j=1;j<n;j++){
		if(ps[j].start>=curEnd){
			cnt++;
			curEnd=ps[j].end;
		}
	}
	cout<<n-cnt<<endl;
}
int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		run();
	}
	return 0;
}
