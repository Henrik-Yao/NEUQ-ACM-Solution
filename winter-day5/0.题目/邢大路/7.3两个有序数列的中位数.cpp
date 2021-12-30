#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100000],b[100000];
     cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int count=0;
	int a_index=0;
	int b_index=0;
	int t=0;
    while(count!=n){
        if(a[a_index]>b[b_index])
        {
            t=b[b_index++];
        }
        else
        {
            t=a[a_index++];
        }
        count++;
    }
    cout<<t<<endl;
    return 0;
}


