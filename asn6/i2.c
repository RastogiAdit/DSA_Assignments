#include<stdio.h>

int maxHeap[10000];
int minHeap[10000];
int maxheapsize=0;
int minheapsize=0;

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void maxheapify(int i){
    int largest=i;
    int lchild=2*i+1;
    int rchild=2*i+2;
    if(lchild<maxheapsize&&maxHeap[largest]<maxHeap[lchild]){
        largest=lchild;
    }
    if(rchild<maxheapsize&&maxHeap[largest]<maxHeap[rchild]){
        largest=rchild;
    }
    if(largest!=i){
        swap(&maxHeap[largest],&maxHeap[i]);
        maxheapify(largest);
    }
}

void minheapify(int i){
    int smallest=i;
    int lchild=2*i+1;
    int rchild=2*i+2;
    if(lchild<minheapsize&&minHeap[smallest]>minHeap[lchild]){
        smallest=lchild;
    }
    if(rchild<minheapsize&&minHeap[smallest]>minHeap[rchild]){
        smallest=rchild;
    }
    if(smallest!=i){
        swap(&minHeap[smallest],&minHeap[i]);
        minheapify(smallest);
    }
}

void maxHeapInsert(int data){
    maxheapsize++;
    maxHeap[maxheapsize-1]=data;
    for(int i=maxheapsize/2;i>=0;i--){
        maxheapify(i);
    }
}

void minHeapInsert(int data){
    minheapsize++;
    minHeap[minheapsize-1]=data;
    for(int i=minheapsize/2;i>=0;i--){
        minheapify(i);
    }
}

int extractMin(){
    int temp=minHeap[0];
    minHeap[0]=minHeap[minheapsize--];
    minheapify(0);
    return temp;
}

int extractMax(){
    int temp=maxHeap[0];
    maxHeap[0]=maxHeap[maxheapsize--];
    maxheapify(0);
    return temp;
}

void balanceHeaps(){
    while(maxheapsize>minheapsize+1){
        minHeapInsert(extractMax());
    }
    while(minheapsize>maxheapsize){
        maxHeapInsert(extractMin());
    }
}

void insert(int data){
    if(maxheapsize==0||data<maxHeap[0]){
        maxHeapInsert(data);
    }else{
        minHeapInsert(data);
    }
    balanceHeaps();
}

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int type;
        scanf("%d",&type);
        if(type==1){
            int data;
            scanf("%d",&data);
            insert(data);
        }else if(type==2){
            printf("%d\n",maxHeap[0]);
        }
    }
}