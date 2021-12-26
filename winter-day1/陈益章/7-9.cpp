#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct customer { 
	char name[4];
	int t, p;
};
 bool cmp(string s1, string s2) ;
int N, M;
map<string, int> friendMap, customerId;	
bool visited[10000];	
vector<string> friends[100], result;	
bool cmp(string s1, string s2);
int main() {
	cin>>N>>M;
	for(int i = 0; i < M; i++) {
		int L;
		scanf("%d", &L);
		for(int j = 0; j < L; j++) {
			char name[4];
			cin>>name;
			friendMap[name] = i;
			friends[i].push_back(name);
		}
	}
	customer customers[N];
	for(int i = 0; i < N; i++) {
		char name[4];
		cin>>name>>customers[i].t>>customers[i].p;
		if(customers[i].p > 60) {	
			customers[i].p = 60;
		}
		strcpy(customers[i].name, name);
		customerId[name] = i;
	}
	int timer = 0;	
	int ptime = customers[0].t;	 
	for(int i = 0; i < N; i++) {
		if(visited[i]) {	
			continue;
		}
		if(friendMap.find(customers[i].name) == friendMap.end()) {	
			if(ptime > customers[i].t) {	
				timer += ptime - customers[i].t;	
				ptime += customers[i].p;	
			}else{
				ptime = customers[i].t + customers[i].p;	
			}
			visited[i] = true;	
			result.push_back(customers[i].name);
			continue;	
		}
		int friendID = friendMap[customers[i].name];
		sort(friends[friendID].begin(), friends[friendID].end(), cmp);	
		for(int j = 0; j < friends[friendID].size(); j++) {
			int id = customerId[friends[friendID][j]];
			if(j > 0 && customers[id].t > ptime){	
				break;
			}
			if(visited[id]){
				continue;
			}
			if(ptime > customers[id].t) {
				timer += ptime - customers[id].t;
				ptime += customers[id].p;
			} else {
				ptime = customers[id].t + customers[id].p;
			}
			visited[id] = true;
			result.push_back(friends[friendID][j]);
		}
	}
	for(int i = 0; i < result.size(); i++) {	
		printf("%s\n", result[i].c_str());
	}
	printf("%.1f\n", timer * 1.0 / N);
	return 0;
}

bool cmp(string s1, string s2) {
	return customerId[s1] < customerId[s2];
}
