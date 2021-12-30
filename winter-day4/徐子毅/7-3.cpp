#include <iostream>
#include <cstring>
#include <stack>
#define inf 999999
using namespace std;
stack<int> path;
int main(){
	int vN,eN;
	cin >> vN >> eN;
	int tablet[vN][vN];
	memset(tablet,-1,sizeof tablet);
	for(int T=1;T<=eN/2;T++){
		int p1,p2,lv;
		cin >> p1 >> p2 >> lv;
		tablet[p1][p2]=lv;
		tablet[p2][p1]=lv;
	}
	int start,end;
	cin >> start >> end;
    if(start==end){
        cout << start << "-->" << end << ":0" << endl;
        return 0;
    }
	int min_distance[vN],Complete[vN],lastv[vN];
	memset(min_distance,inf,sizeof min_distance);
	memset(Complete,0,sizeof Complete);
	min_distance[start]=0;
	while(Complete[end]==0){
		int minv=inf,minp=0;
		for(int i=0;i<vN;i++){
			if(minv>min_distance[i]&&Complete[i]==0){
				minp=i;
				minv=min_distance[i];
			}
		}
		Complete[minp]=1;
		for(int i=0;i<vN;i++){
			if(tablet[minp][i]!=-1){
				if(min_distance[i]>min_distance[minp]+tablet[minp][i]){
					min_distance[i]=min_distance[minp]+tablet[minp][i];
					lastv[i]=minp;
				}
			}
		}
	}
	int p=end;
	int min_path=min_distance[p];
	while(p!=start){
		path.push(p);
		p=lastv[p];
	}
	cout << start;
	while(!path.empty()){
		cout << "-->" << path.top();
		path.pop();
	}
	cout << ":" << min_path << endl;
	return 0;
}