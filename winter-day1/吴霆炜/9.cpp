#include <bits/stdc++.h>
using namespace std;
 
struct customer {
	char name[4];
	int arr, pro;
};
 
int N, M;
unordered_map<string, int> friendMap, customerId;
bool visited[10000];
vector<string> friends[100], result;
 
inline bool cmp(string s1, string s2) {
	return customerId[s1] < customerId[s2];
}
 
int main() {
	scanf("%d %d", &N, &M);
	fill(visited, visited + N, false); 
	for(int i = 0; i < M; i++) {
		int L;
		scanf("%d", &L);
		for(int j = 0; j < L; j++) {
			char name[4];
			scanf("%s", name);
			friendMap[name] = i;
			friends[i].push_back(name);
		}
	}
	customer customers[N];
	for(int i = 0; i < N; i++) {
		char name[4];
		scanf("%s %d %d", name, &customers[i].arr, &customers[i].pro);
		if(customers[i].pro > 60) {
			customers[i].pro = 60;
		}
		strcpy(customers[i].name, name);
		customerId[name] = i;
	}
	int totalTime = 0;
	int _temp = customers[0].arr;
	for(int i = 0; i < N; i++) {
		if(visited[i]) {
			continue;
		}
		if(friendMap.find(customers[i].name) == friendMap.end()) {
			if(_temp > customers[i].arr) {
				totalTime += _temp - customers[i].arr;
				_temp += customers[i].pro;	
			}else{
				_temp = customers[i].arr + customers[i].pro;	
			}
			visited[i] = true;	
			result.push_back(customers[i].name);
			continue;	
		}
		int friendID = friendMap[customers[i].name];
		sort(friends[friendID].begin(), friends[friendID].end(), cmp);	
		for(int j = 0; j < friends[friendID].size(); j++) {
			int id = customerId[friends[friendID][j]];
			if(j > 0 && customers[id].arr > _temp){	
				break;
			}
			if(visited[id]){
				continue;
			}
			if(_temp > customers[id].arr) {
				totalTime += _temp - customers[id].arr;
				_temp += customers[id].pro;
			} else {
				_temp = customers[id].arr + customers[id].pro;
			}
			visited[id] = true;
			result.push_back(friends[friendID][j]);
		}
	}
	for(int i = 0; i < result.size(); i++) {	
		printf("%s\n", result[i].c_str());
	}
	printf("%.1f\n", totalTime * 1.0 / N);
	return 0;
}
 
