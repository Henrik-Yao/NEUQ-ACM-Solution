#include <bits/stdc++.h>
using namespace std;
int arr[1001],m[1001]={0},l[1001],n;
void dp(){
	int i,j,max;
	m[0]=1;
	l[0]=-1;
	for(i=0;i<n;i++) 
	{
		max=0;
		for(j=0;j<i;j++)
			if(arr[i]>arr[j]&&max<m[j])
			{
				max=m[j];
				l[i]=j;
			}
		m[i]=max+1;
	}
}
void Output(){
	int i,max=0;
	int ant[1001],k=0;
    for(i=0;i<n;i++)
		if(m[i]>m[max])
			max=i;
	cout<<m[max]<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
            dp();
            Output();
        if(T!=0) cout<<endl;
    }
    
    return 0;
}
