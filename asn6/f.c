#include<stdio.h>
int count=0;

void merge(int* arr,int l,int mid,int h,int n){
    int temp[n];
    int left=l;
    int right=mid+1;
    int tempIndex=0;
    while(left<=mid&&right<=h){
        if(arr[left]<=arr[right]){
            temp[tempIndex++]=arr[left++];
        }else{
            count+=(mid-left+1);
            temp[tempIndex++]=arr[right++];
        }
    }
    while(left<=mid){
        temp[tempIndex++]=arr[left++];
    }
    while(right<=h){
        temp[tempIndex++]=arr[right++];
    }
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
}

void mergeSort(int* arr,int l,int h,int n){
    if(l>=h){
        return;
    }
    int mid=(l+h)/2;
    mergeSort(arr,l,mid,n);
    mergeSort(arr,mid+1,h,n);
    merge(arr,l,mid,h,n);
    
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //int h=solve(arr,0,n-1);
    mergeSort(arr,0,n-1,n);
    
    printf("\n%d",count);
}