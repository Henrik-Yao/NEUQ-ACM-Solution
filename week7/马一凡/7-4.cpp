#include <iostream> 
#include <cstring> 
#include <algorithm>
using namespace std; 
 
int a[1000],b[1000]; 
int maxLen[1000][1000]; 

int main(){ 
	int t,n; 
	cin >> t; 
	for(int k=0; k<t; k++){ 
	if(k) cout << endl;
		cin >> n;
		for(int q=0; q<n; q++){
			cin >> a[q];
		}
		memset(b, 0, n*sizeof(int));
		memcpy(b, a, n * sizeof(int));
		sort(b,b+n);
		int nTmp;   
		int i,j;   
		for( i = 0;i <= n; i ++ )    
			maxLen[i][0] = 0;   
		for( j = 0;j <= n; j ++ )    
			maxLen[0][j] = 0; 
  		for( i = 1;i <= n;i ++ ) {    
			for( j = 1; j <= n; j ++ ){     
				if( a[i-1] == b[j-1] )          
					maxLen[i][j] =  maxLen[i-1][j-1] + 1;     
				else           
					maxLen[i][j] = max(maxLen[i][j-1],maxLen[i-1][j]);    
			}   
		}   
		cout <<  maxLen[n][n] << endl;  
	}  
	return 0;  
} 
