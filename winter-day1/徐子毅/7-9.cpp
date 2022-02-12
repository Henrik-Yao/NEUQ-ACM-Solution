#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
struct Human{
	string name;
	int T;
	int P;
	int WaitingTime;
	bool solved=false;
};
map<string,int> Friends;
map<string,int>::iterator Iter;
queue<Human> Peoples;
int main(){
	int N,M;
	cin>>N>>M;
	int num;
	for(int i=1;i<=M;i++){
		cin >> num;
		string name;
		for(int T=1;T<=num;T++) {cin >> name;Friends[name]=i;}
	}
	Human a[N];
	for(int G=0;G<N;G++){
		cin>>a[G].name>>a[G].T>>a[G].P;
		if(a[G].P>60) a[G].P=60;
	}
	int timeconsume=0;
	for(int i=0;i<N;i++){
		if(a[i].solved==false){
			if(a[i].T>timeconsume) timeconsume=a[i].T;
			a[i].WaitingTime=timeconsume-a[i].T;
			timeconsume+=a[i].P;
			Iter=Friends.find(a[i].name);
			if(Iter==Friends.end()){
				a[i].solved=true;
				Peoples.push(a[i]);
			}else{
				a[i].solved=true;
				Peoples.push(a[i]);
				for(int j=i+1;j<N;j++){
					if(Friends[a[j].name]==Iter->second&&a[j].solved==false&&a[j].T<=timeconsume){
						a[j].WaitingTime=timeconsume-a[j].T;
						a[j].solved=true;
						Peoples.push(a[j]);
						timeconsume+=a[j].P;
					}
				}
			}
		}
	}
	int totalwaitingtime=0;
	while(!Peoples.empty()){
		totalwaitingtime+=Peoples.front().WaitingTime;
		cout << Peoples.front().name << endl;
		Peoples.pop();
	}
	printf("%.1f",(double)totalwaitingtime/(double)N);
}