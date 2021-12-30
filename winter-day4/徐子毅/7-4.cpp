#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define inf 999999
vector<int> maxpathc1,maxpathc2;
int main(){
	int city,road;
	cin >> city >> road;
	int dp[city+5][city+5];
	int path[city+5][city+5];
	for(int i=0;i<city;i++) for(int j=0;j<city;j++){
		path[i][j]=j;
		if(i==j) dp[i][j]=0;
	}
	memset(dp,inf,sizeof dp);
	for(int T=0;T<road;T++){
		int c1,c2,distant;
		cin >> c1 >> c2 >> distant;
		dp[c1][c2]=distant;
	}
	int inter,city1,city2;
	for(inter=0;inter<city;inter++){
		for(city1=0;city1<city;city1++){
			for(city2=0;city2<city;city2++){
				if(dp[city1][city2]>dp[city1][inter]+dp[inter][city2])  {
					dp[city1][city2]=dp[city1][inter]+dp[inter][city2];
					path[city1][city2]=path[city1][inter];
				}
			}
		}
	}
	for(int i=0;i<city;i++) dp[i][i]=0;
	for(int TTT=1;TTT<=2;TTT++){
		int start,end;
		cin >> start >> end;
		int i=start,j=end;
        if(start==end) {cout << start << "->" << end << ":0" << endl;continue;}
		if(dp[start][end]>=inf/2){cout << start << "->" << end << ":-1" << endl; continue;}
		int t=start;
		while(t!=end){
			cout << t << "->";
			t=path[t][end];
		}
		cout << end << ":" << dp[start][end] << endl;
	}
	int maxpathstart,maxpathend,maxlength=-inf;
	for(int i=0;i<city;i++) {
		for(int j=0;j<city;j++){
			if(dp[i][j]>=maxlength&&dp[i][j]<=inf/2){
				maxlength=dp[i][j];
			}
		}
	}
	int longest_start=0,longest_end=0;
	bool find=false;
	for(int i=0;i<city;i++) {
		if(find) break;
		for(int j=0;j<city;j++){
			if(dp[i][j]==maxlength){
				longest_start=i;
				longest_end=j;
				find=true;
				break;
			}
		}
	}
	int i=longest_start,j=longest_end;
    if(longest_start==longest_end) {cout << longest_start << "->" << longest_end << ":0" << endl;return 0;}
	if(dp[longest_start][longest_end]>=inf/2){cout << longest_start << "->" << longest_end << ":-1" << endl;return 0;}
	int t=longest_start;
	while(t!=longest_end){
		cout << t << "->";
		t=path[t][longest_end];
	}
	cout << longest_end << ":" << dp[longest_start][longest_end] << endl;
}