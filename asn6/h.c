#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a heap node
typedef struct {
    int value; // Value of the element
    int arrayIndex; // Index of the array to which the element belongs
    int elementIndex; // Index of the element in its array
} HeapNode;

// Function to swap two heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heapify function to maintain heap property
void minHeapify(HeapNode* heap, int size, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild].value < heap[smallest].value) {
        smallest = leftChild;
    }

    if (rightChild < size && heap[rightChild].value < heap[smallest].value) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Build Min Heap from an array
void buildMinHeap(HeapNode* heap, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

// Function to merge k sorted arrays using min heap
void mergeSortedArrays(int** arrays, int* sizes, int k) {
    // Create a min heap and initialize it with the first element from each array
    HeapNode* heap = (HeapNode*)malloc(k * sizeof(HeapNode));
    for (int i = 0; i < k; i++) {
        heap[i].value = arrays[i][0];
        heap[i].arrayIndex = i;
        heap[i].elementIndex = 0;
    }

    // Build the initial min heap
    buildMinHeap(heap, k);

    // Merge and print the result
    while (heap[0].value != INT_MAX) {
        // Print the minimum element
        printf("%d ", heap[0].value);

        // Replace the minimum element with the next element from its array
        if (heap[0].elementIndex < sizes[heap[0].arrayIndex] - 1) {
            heap[0].value = arrays[heap[0].arrayIndex][++heap[0].elementIndex];
        } else {
            // If the array is exhausted, replace it with INT_MAX
            heap[0].value = INT_MAX;
        }

        // Heapify to maintain the heap property
        minHeapify(heap, k, 0);
    }

    free(heap);
}

int main() {
    int k;
    scanf("%d", &k);

    int** arrays = (int**)malloc(k * sizeof(int*));
    int* sizes = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        scanf("%d", &sizes[i]);
        arrays[i] = (int*)malloc(sizes[i] * sizeof(int));

        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    // Merge and print the result
    mergeSortedArrays(arrays, sizes, k);

    // Free allocated memory
    for (int i = 0; i < k; i++) {
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);

    return 0;
}