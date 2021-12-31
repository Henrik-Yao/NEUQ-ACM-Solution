#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[1001],b[1001];
	int m,n;
	int i,j;
	int longest = 1;
	cin>>m;
    int s =m;
	for(int k = 0; k < m; k++){
        if(k!=0)
		cout<<endl;
	cin>>n;
        longest = 1;
		for(i= 0 ;i<n;i++)
			cin>>a[i];
		b[0]=1;
		for(i=1;i<n;i++)
		{
			b[i]= 1;
			for(j=0;j<i;j++)
				if(a[j]<a[i])
					b[i]=max(b[j]+1,b[i]);
        }
	for(int i = 0; i < n; i++){
            longest = max(longest,b[i]);
    }
cout<<longest<<endl;
}
	return  0 ;
}


