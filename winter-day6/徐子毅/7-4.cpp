#include <iostream>
using namespace std;
long long a[1000005],S[1000005];
long long ans=0;
void Merge(long long a[],long long S[],long long Front,long long End){
	if(Front==End) return;
	else{
		long long mid=(Front+End)/2;
		Merge(a,S,Front,mid);
		Merge(a,S,mid+1,End);
		long long i=Front,j=mid+1,k=Front;
		while(i<=mid&&j<=End){
			if(a[i]<=a[j]){
				S[k]=a[i];
				k++;
				i++;
			}else{
				S[k]=a[j];
				k++;
				j++;
				ans=ans+mid-i+1;
			}
		}
		while(i<=mid){S[k]=a[i];k++;i++;}
		while(j<=End){S[k]=a[j];k++;j++;}
		for(long long i=Front;i<=End;i++) a[i]=S[i];
	}
}
int main(){
	long long n;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	Merge(a,S,1,n);
	printf("%lld",ans);
	return 0;
}