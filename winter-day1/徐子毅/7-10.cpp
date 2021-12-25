#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
queue<int> trainsbefore;
queue<int> trail[100];
int main(){
	int num=0;
	cin >> num;
	int order;
	for(int i=0;i<num;i++){
		cin >> order;
		trainsbefore.push(order);
	}
	int maxtrail=0;
	int where1=0;
	while(!trainsbefore.empty()){
		bool found=false;
		int intrain=trainsbefore.front();
		for(int i=1;i<=maxtrail;i++){
			if(trail[i].back()>intrain){
				if(intrain==1) where1=i;
				trail[i].push(intrain);
				found=true;
				break;
			}
		}
		if(!found){
				maxtrail++;
				if(intrain==1) where1=maxtrail;
				trail[maxtrail].push(intrain);
		}
		trainsbefore.pop();
	}
    if(!trail[where1].empty()){
		cout << trail[where1].front();
		trail[where1].pop();
	}
	while(!trail[where1].empty()){
		cout << " " << trail[where1].front();
		trail[where1].pop();
	}
    cout << endl;
	cout << maxtrail <<endl;
	return 0;
}