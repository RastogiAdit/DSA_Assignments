#include<stdio.h>

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

// void heapify(int* arr,int N,int i){
//     int largest=i;
//     int leftChild=2*i+1;
//     int rightChild=2*i+2;
//     if(leftChild<N&&arr[leftChild]>arr[largest]){
//         largest=leftChild;
//     }
//     if(rightChild<N&&arr[rightChild]>arr[largest]){
//         largest=rightChild;
//     }
//     if(largest!=i){
//         swap(&arr[largest],&arr[i]);
//         heapify(arr,N,largest);
//     }
// }

void heapify(int* arr,int N,int i){
    int largest=i;
    int leftChild=2*i+1;
    int rightChild=2*i+2;
    if(leftChild<N&&arr[leftChild]>arr[i]){
        largest=leftChild;
    }
    if(rightChild<N&&arr[rightChild]>arr[largest]){
        largest=rightChild;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,N,largest);
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int num[k];
    for(int i=0;i<k;i++){
        num[i]=arr[i];
    }
    for(int i = k / 2 ; i >= 0; i--) heapify(num,k,i);
    for(int i=k;i<n;i++){
        if(num[0]>arr[i]){
            // printf("%d ",num[0]);
            num[0]=arr[i];
            heapify(num,k,0);
        }
    }
    //printf("\n");
    int sum=0;
    for(int i=0;i<k;i++){
        //printf("%d ",num[k]);
        sum+=num[i];
    }
    printf("\n%d",sum);
}