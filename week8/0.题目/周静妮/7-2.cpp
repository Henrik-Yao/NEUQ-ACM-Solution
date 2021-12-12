#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	vector<int>v;
	for(int i=0;i<t;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	int count=0;
	int max=0,temp2=0,max1=0;
	t--;
	while(1){
		max1=0;
		temp2=max;
		if(v[temp2]>=t){ 
			count++;
			break;
		}
		else{
			max=temp2+v[temp2];
			for(int j=temp2+1;j<=temp2+v[temp2];j++)if(v[j]>=v[max]&&v[j]+j-temp2>v[temp2])max=j;
			max1=v[max]+max;
            for(int j=max;j<=temp2+v[temp2];j++)
			{
				if(v[j]+j>max1){
					max1=v[j]+j;
					max=j;
				}
			}
			t-=max-temp2;
			count++;
		}	
	}	
	cout<<count;
	return 0;
}

