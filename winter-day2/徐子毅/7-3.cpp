#include <iostream>
#include <stack>
using namespace std;
int main(){
	int T;
	cin >> T;
	for(int TT=1;TT<=T;TT++){
		int father[10005],level[10005],n=1;
		stack<int> st;
		int num=0;
		cin >> num;
        if(num<0) num+=5000;
		level[num]=n++;
		st.push(num);
		while(!st.empty()){
			cin >> num;
            if(num<0) num+=5000;
			if(num!=0){
				father[num]=st.top();
				level[num]=n++;
				st.push(num);
			}else{
				n--;
				st.pop();
			}
		}
		int n1,n2;
		cin >> n1;
		cin >> n1 >> n2;
        if(n1<0) n1+=5000;
        if(n2<0) n2+=5000;
		if(level[n1]>level[n2]){
			int level_jump=level[n1]-level[n2];
			while(level_jump--){
				n1=father[n1];
			}
		}
		if(level[n1]<level[n2]){
			int level_jump=level[n2]-level[n1];
			while(level_jump--){
				n2=father[n2];
			}
		}
		while(n1!=n2){
			n1=father[n1];
			n2=father[n2];
		}
		cout << n1 << endl;
	}
}