#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char a[50010]={0},b[25]={0};
	int n,k=0,w=0;
	int m=0;
	int la,lb,i=0,j=0,count=0;
	cin >> n;
	scanf("%s",a);
	la = strlen(a);

	
	for(i=0; i<n; i++){
		
		k=0;
		w = 0;
		count = 0;
		scanf("%s",b);
		lb = strlen(b);
		
		for(j=0; j<la; j++){
			m=0;
			for(k=j; k<j+lb; k++){
				if(a[k]!=b[m]) break;
				m++;
			}
			if(m==lb) count++;
			
		}
		cout << count ;
		if(i<n-1) cout << endl;
	}
	
	return 0;
}
