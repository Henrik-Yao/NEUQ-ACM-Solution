#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
    int a,n,times=0,max=0,temp=0,max1=0;
    ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;v.push_back(a);
	}
	n--;
	while(1){
		max1=0;temp=max;
		if(v[temp]>=n){
			times++;break;
		}
		else{
			max=temp+v[temp];
			for(int j=temp+1;j<=temp+v[temp];j++)
                if(v[j]>=v[max] && v[j]+j-temp>v[temp]) max=j;
			max1=v[max]+max;
            for(int j=max;j<=temp+v[temp];j++){
				if(v[j]+j>max1){
					max1=v[j]+j;
					max=j;
				}
			}
			n=n-(max-temp);
			times++;
		}
	}
	cout<<times;
	return 0;
}
