#include<iostream>
using namespace std;

int main(){
	int n;
	int m, num;
	scanf("%d",&n);

	for(int i=0; i<n; i++){
		int num_1 = 0, num_2 = 1, num_3=2;
		scanf("%d",&m);
		if(m == 1) num_3 = 0;
		else if(m == 2) num_3 = 1;
		else if(m == 3) num_3 = 2;
		else {
			for(int j=1; j<=m-3; j++){
			num_1=num_2;
			num_2 = num_3;
			num_3 = num_1+num_2;
			}
		}
		printf("%d\n",num_3); 
	}

	
	
	return 0;
}


