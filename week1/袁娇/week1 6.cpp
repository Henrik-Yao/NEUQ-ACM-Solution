#include<iostream> 
using namespace std;
int main (){
	int n,v,t,T,m,max;
	cin>>n>>T;
    cin>>v>>t;
	int s=n-1;
	if(t>T)  m=v-t+T;
    else m=v;
   max=m;
	while(s--){
		cin>>v>>t;
	    if(t>T)  m=v-t+T;
        else m=v;
		if(m>max)
		max=m;
        }
	cout<<max;
	return 0;
}
