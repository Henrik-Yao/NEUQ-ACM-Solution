#include<iostream>
using namespace std;

int line(int rr[],int ss[],int n, int m)
{
	int k = 0,i=0,j=0;
    while((j<=n)&&(i<=m)){
        if(rr[i]<=rr[j])
        {
            ss[k] = rr[i];
            i++;
            k++;
        }
        else
        {
            ss[k]=rr[j];
            j++;
            k++;
        }
	}
	while(i<=m) ss[k++]=rr[i++];
    while(j<=n) ss[k++]=rr[j++];
    
    return 0;
}
	
	
int main()
{
    int i,j;
    int n,m;
	int t;
	cin >> t;
   for(i=0; i<t; i++){
   		int a[1000]= {0};
   		int b[1000]={0};
   		int c[1000]={0};
   		cin >> m ;
   		for(j=0; j<m; j++) cin >> a[j];
   		cin >> n;
   		for(j=0; j<n; j++) cin >> b[j];
   		
	int k = 0,i=0,j=0;
    while((j<n)&&(i<m)){
        if(a[i]<b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
        if(j==n){
        	while(i<m){
        		c[k]=a[i];
				k++;
				i++;	
			} 
        
		} 
   		else if(i==m) {
   			while(j<n){
   				c[k]=b[j];
   				k++;
   				j++;
			   } 
		   }
 	
   }for(j=0; j<k-1; j++) cout << c[j] << " ";
   cout << c[k-1] << endl;
   }
    return 0;
}

