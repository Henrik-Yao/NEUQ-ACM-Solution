#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> Group[1005];
map<int,int> GetGroup;
int geted[1005];
int main(){
	int n,m,q;
	cin >> n >> m >> q;
	int maxgroup=0;
	int p1,p2;
	for(int T=1;T<=m;T++){
		cin >> p1 >> p2;
		if(geted[p1]==1&&geted[p2]==1) {
			if(GetGroup[p1]==GetGroup[p2]) continue;
			else {
				int BigGroup;
				int SmallGroup;
				if(GetGroup[p1]>GetGroup[p2]){
					BigGroup=GetGroup[p1];
					SmallGroup=GetGroup[p2];
				}else{
					BigGroup=GetGroup[p2];
					SmallGroup=GetGroup[p1];
				}
				for(int i=0;i<Group[BigGroup].size();i++){
					Group[SmallGroup].push_back(Group[BigGroup][i]);
					GetGroup[Group[BigGroup][i]]=SmallGroup;
				}
				Group[BigGroup].clear();
			}
		}
		else if(geted[p1]==1&&geted[p2]==0){
			Group[GetGroup[p1]].push_back(p2);
			GetGroup[p2]=GetGroup[p1];
			geted[p2]=1;
		}else if(geted[p1]==0&&geted[p2]==1){
			Group[GetGroup[p2]].push_back(p1);
			GetGroup[p1]=GetGroup[p2];
			geted[p1]=1;
		}
		else if(geted[p1]==0&&geted[p2]==0){
			maxgroup++;
			Group[maxgroup].push_back(p1);
			Group[maxgroup].push_back(p2);
			GetGroup[p1]=maxgroup;
			GetGroup[p2]=maxgroup;
			geted[p1]=1;
			geted[p2]=1;
		}
	}
	int undefined=n;
	for(int i=1;i<=1005;i++) if(geted[i]==1) undefined--;
	for(int T=1;T<=q;T++){
		int id1,id2;
		cin >> id1 >> id2;
		bool _find=false;
		for(int i=0;i<Group[GetGroup[id1]].size();i++){
			if(Group[GetGroup[id1]][i]==id2){
				_find=true;
				cout << "In the same gang." << endl;
			}
		}
		if(!_find) cout << "In different gangs." << endl;
	}
	int sumgroup=0;
	for(int i=0;i<=1005;i++) if(!Group[i].empty()) sumgroup++;
	cout << sumgroup+undefined << endl;
}