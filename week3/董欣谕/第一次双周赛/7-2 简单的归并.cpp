#include <bits/stdc++.h>
using namespace std;
int a[101],temp[101],b[101];
int main() {
	int i,j,t,len1,len2;
	cin>>t;
	while (t--) {
		cin>>len1;
		for (i=1;i<=len1;i++)
			cin>>a[i];
		cin>>len2;
		for (i=1;i<=len2;i++)
			cin>>b[i];
		int k=0;
		i=1;
		j=1;
		while (i<=len1&&j<=len2) {
			if (a[i]<=b[j]) temp[k++]=a[i++];
			else temp[k++]=b[j++];
		}
		while (i<=len1) temp[k++]=a[i++];
		while (j<=len2) temp[k++]=b[j++];
		for (i=0; i<len1+len2 ; i++) 
            if (i!=len1+len2-1) cout<<temp[i]<<" ";
	        else cout<<temp[i];
        cout<<endl;
    }
	return 0;
}
