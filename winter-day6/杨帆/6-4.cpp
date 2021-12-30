#include<iostream>
using namespace std;
const int N = 1e6;
long long a[N],temp[N];
long long cnt=0;

void merge(int left,int mid,int right);
int sort_(int left,int right);

int main()
{
	int n,i;
	cin >> n;
	for(i=1; i<=n; i++)
	    cin >> a[i];
	sort_(1,n);
	cout << cnt;
	return 0;
}

int sort_(int left,int right){
	if(left>=right)
	return cnt;
	int mid = (left+right)>>1;
	sort_(left,mid);
	sort_(mid+1,right);
	merge(left,mid,right);
}

void merge(int left,int mid,int right){
	int i = left,j = mid+1,k = left;
	while(i <= mid && j <= right){
		if(a[i] <= a[j]){
			temp[k] = a[i];
			k++,i++;
		}
		else{
			cnt+=mid-i+1;
			temp[k]=a[j];
			k++,j++;
		}
	}
	while(i <= mid){
		temp[k]=a[i];
		k++,i++;
	}
	while(j <= right){
		temp[k] = a[j];
		k++,j++;
	}
	for(i=left; i<=right; i++){
		a[i]=temp[i];
	}
}
