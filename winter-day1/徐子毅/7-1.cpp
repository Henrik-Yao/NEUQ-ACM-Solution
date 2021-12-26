#include <iostream>
using namespace std;
long long t[1000005];
long long N;
long long lowbit(long long n){
	return (n)&(-n);
}
void updata_data(long long s1,long long s2){
	for(long long i=s1;i<=N;i+=lowbit(i)) t[i]+=s2;
}
long long sum_data(long long s){
	long long sum=0;
	for(long long i=s;i>0;i-=lowbit(i)) sum+=t[i];
	return sum;
}
int main(){
	long long q,num;
	cin >> N >> q;
	for(long long i=1;i<=N;i++){
		cin >> num;
		updata_data(i,num);
	}
	long long op;
	for(long long T=1;T<=q;T++){
		cin >> op;
		if(op==2){
			long long s1,s2;
			cin >> s1 >> s2;
			cout << sum_data(s2)-sum_data(s1-1	) << endl;
		}else if (op==1){
			long long s1,s2;
			cin >> s1 >> s2;
			updata_data(s1,s2);
		}
	}
}