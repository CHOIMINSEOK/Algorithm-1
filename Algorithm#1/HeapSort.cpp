//
//  HeapSort.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 08/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include "HeapSort.hpp"

int* HeapSort::sort(int *arr){
    int arrSize = arr[SIZE];
    int* newArr = new int[arrSize];
    newArr[SIZE] = arrSize;
    
    buildMaxHeap(arr);
    for (int i=arrSize-1; i>1; i--) {
        newArr[i] = arr[1];
        Commons::swap(&arr[1], &arr[i]);
        arr[SIZE]--;
        maxHeapify(arr, 1);
    }
    newArr[1] = arr[1];
    
    return newArr;
}

void HeapSort::maxHeapify(int *arr, int rootIdx){
    int leftChildIdx = rootIdx*2, rightChildIdx = rootIdx*2+1;
    int heapSize = arr[SIZE]-1;
    int largest = rootIdx;
    
    
    if (leftChildIdx<=heapSize && arr[leftChildIdx]>arr[largest]) largest = leftChildIdx;
    
    if (rightChildIdx<=heapSize && arr[rightChildIdx]>arr[largest]) largest = rightChildIdx;
    
    if (largest != rootIdx) {
        Commons::swap(&arr[rootIdx], &arr[largest]);
        maxHeapify(arr, largest);
    }
}

void HeapSort::buildMaxHeap(int *arr){
    int StartIdx = arr[SIZE]/2;
    for (int i=StartIdx; i>0 ; i--) {
        maxHeapify(arr, i);
    }
}
