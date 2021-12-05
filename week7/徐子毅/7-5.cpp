#include <iostream>
using namespace std;
int things,maxkilo,bagrommax[1505];
int main()
{
    while(cin >> things >> maxkilo){
        for(int i=0;i<=maxkilo+3;i++) bagrommax[i]=0;
    	int value[things+1],kilo[things+1];
    	for(int i=1;i<=things;i++){
    		cin >> kilo[i];
    	}
    	for(int i=1;i<=things;i++){
    		cin >> value[i];
    	}
    	kilo[0]=value[0]=0;
    	for(int i=1;i<=things;i++){
    		int j;
    		for(j=maxkilo;j>0;j--){
    			if(kilo[i]<=j) bagrommax[j]=max(bagrommax[j],bagrommax[j-kilo[i]]+value[i]);
    		}
    	}
    	cout << bagrommax[maxkilo] << endl;
    }
    return 0;    
}