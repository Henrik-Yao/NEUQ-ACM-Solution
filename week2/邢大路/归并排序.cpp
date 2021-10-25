#include<bits/stdc++.h>
using namespace std;
int data[100001];
int n;
void merge(int *data,int begin,int end,int *result){
    int left_length=(end-begin+1)/2+1;
    int left_index=begin;
    int right_index=begin+left_length;
    int result_index=begin;
    while(left_index<begin+left_length&&right_index<end+1){
        if(data[left_index++]<=data[right_index++])result[result_index++]=data[left_index++];
        else result[result_index++]=data[right_index++];
    }
    while(left_index<begin+left_length)result[result_index++]=data[left_index++];
    while(right_index<end+1)result[result_index++]=data[right_index++];
    
}
void merge_sort(int *data,int begin,int end,int *result){
    if(begin==end-1){
        if(data[begin]>data[end]){
        	int temp=data[begin];
        	data[begin]=data[end];
        	data[end]=temp;
		}
        return;
    }
    else if(begin==end)return;
    else {
        merge_sort(data,begin,(end-begin+1)/2+begin,result);
        merge_sort(data,(end-begin+1)/2+begin+1,end,result);
        merge(data,begin,end,result);
        for(int i=begin;i<=end;++i){
            data[i]=result[i];
        }
    }
}
int main(){
    cin>>n;
    int result[n];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    int begin=0;
    int end=n-1;
    merge_sort(data,begin,end,result);
    for(int i=0;i<n;i++){
        printf("%d ",data[i]);
    }
    return 0;
}
