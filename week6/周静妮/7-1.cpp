#include<bits/stdc++.h>
using namespace std;
int Next[100001],ans=0;
string s,t;
void getNext(){
	int j =0, k =-1;
    Next[0]=-1;   
        while(j < s.size()){
            if(k ==-1|| s[j]== s[k]){
            j++;
            k++;
            Next[j]= k;
     }
        else{
        	k =Next[k];
		}     
     }  
}
void kmp(){
	int i=0,j=0;
	while(j<t.size()){
		if(t[j]==s[i]||i==-1){
			i++;
			j++;
		}
		else {
			i=Next[i];
		}
		if(i==s.size()){
			ans++;
		}		
	}
}
int main ()
{
	cin>>t>>s;
	getNext();
	kmp();
	cout<<ans<<endl;
	return 0;
}


