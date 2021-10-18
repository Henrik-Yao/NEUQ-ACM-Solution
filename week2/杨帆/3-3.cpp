#include<bits/stdc++.h>
using namespace std;
const int k=100000+5;
int arr[k];
void merge(int arr[],int tempArr[],int left,int mid,int right){
    int l_pos=left,r_pos=mid+1;
    int pos=left;
    while(l_pos<=mid&&r_pos<=right){
        if(arr[l_pos]<arr[r_pos])
            tempArr[pos++]=arr[l_pos++];
        else
            tempArr[pos++]=arr[r_pos++];
    }
    while(l_pos<=mid)
        tempArr[pos++]=arr[l_pos++];
    while(r_pos<=right)
        tempArr[pos++]=arr[r_pos++];
    while(left<=right){
        arr[left]=tempArr[left];
        left++;
    }
}
void msort(int arr[],int tempArr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        msort(arr,tempArr,left,mid);
        msort(arr,tempArr,mid+1,right);
        merge(arr,tempArr,left,mid,right);
    }
}
void merge_sort(int arr[],int n){
    int *tempArr=(int *)malloc(n*sizeof(int));
    if(tempArr){
        msort(arr,tempArr,0,n-1);
        free(tempArr);
    }
}
int main(){
		int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    merge_sort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
