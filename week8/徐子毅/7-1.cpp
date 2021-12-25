#include <iostream>
using namespace std;
struct timestable{
    int start;
    int end;
};
int main(){
    int abc;
    cin >> abc;
    for(int kkk=0;kkk<abc;kkk++){
        int n;
        cin >> n;
        timestable ts[n];
        for(int i=0;i<n;i++){
			cin >> ts[i].start >> ts[i].end;
        }
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(ts[j].end>ts[j+1].end) swap(ts[j],ts[j+1]);
		}
    }
	int count=1;int endtime=0;
	for(int i=0;i<n;i++){
		if(ts[i].start>=ts[endtime].end){
			count++;
			endtime=i;
		}
	}
	cout << n-count << endl;
    }
    return 0;
}