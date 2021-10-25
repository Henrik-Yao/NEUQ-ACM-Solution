#include <iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	int memofront[100005],memoback[100005];
	int a[N];
	for(int i=0;i<N;i++) cin >> a[i];
	int tap=1,maxweight=0;
	if(N==2) {cout << 2 << endl; return 0;}
	for(int i=0;i<100005;i++) {memofront[i]=0;memoback[i]=0;}
	int frontweight=0,backweight=0;
	//第一次扫描，此时tap=1
	for(int i=0;i<tap;i++){
		if(memofront[a[i]]==1) continue;
		else {
			memofront[a[i]]=1;
		        frontweight++;
		}
	}
	for(int i=tap;i<N;i++){
		if(memoback[a[i]]>0) {memoback[a[i]]++;continue;}
		else {
			memoback[a[i]]=1;
		        backweight++;
		}
	}
	int weight=frontweight+backweight;
	/*cout << "This is tap " << tap << endl;
	cout << "At this time:" << endl;
	printf("memofront[%d]=%d\n",a[tap],memofront[a[tap]]);
	printf("memoback[%d]=%d\n",a[tap],memoback[a[tap]]);
	cout << "Frontweight is " << frontweight << endl;
	cout << "Backweight is " << backweight << endl;
	cout << "-----------------" << endl;*/
	//开始移动插板
	for(tap=1;tap<N-1;tap++){
		if(memofront[a[tap]]==0) {frontweight++;memofront[a[tap]]++;}
		if(backweight>0){
			if(memoback[a[tap]]>1) memoback[a[tap]]--;
			else if (memoback[a[tap]]==1) {
				memoback[a[tap]]=0;backweight--;
			}
		}
		int weight=frontweight+backweight;
		if(weight>maxweight) maxweight=weight;
	/*	cout << "This is tap " << tap << endl;
		cout << "At this time:" << endl;
		printf("memofront[%d]=%d\n",a[tap],memofront[a[tap]]);
		printf("memoback[%d]=%d\n",a[tap],memoback[a[tap]]);
		cout << "Frontweight is " << frontweight << endl;
		cout << "Backweight is " << backweight << endl;
		cout << "-----------------" << endl;*/
	}
	cout << maxweight << endl;
	return 0;
}
