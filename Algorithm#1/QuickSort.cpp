//
//  QuickSort.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 08/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include "QuickSort.hpp"

void QuickSort::recurSort(int *arr, int start, int end){
    if(start >= end) return;
    int pivot = arr[end];
    
    int smallGrpEnd = start-1;
    
    for (int i=start; i<=end; i++) {
        if(arr[i] < pivot){
            smallGrpEnd++;
            Commons::swap(&arr[smallGrpEnd], &arr[i]);
        }
    }
    
    Commons::swap(&arr[smallGrpEnd+1], &arr[end]);
    recurSort(arr, start, smallGrpEnd);
    recurSort(arr, smallGrpEnd+2, end);
    
}

void QuickSort::seqSort(int *arr){
    int startIdx = 1;
    int pivotIdx = arr[SIZE] - 1;
    int smallGrpEnd, pivot;

    stack<int> workStack;

    workStack.push(startIdx);
    workStack.push(pivotIdx);
    
    while(!workStack.empty()){
        pivotIdx = workStack.top(); workStack.pop();
        startIdx = workStack.top(); workStack.pop();
        
        if(startIdx >= pivotIdx) continue;
        
        smallGrpEnd = startIdx - 1;
        pivot = arr[pivotIdx];
        
        for (int i=startIdx; i<pivotIdx+1; i++) {
            if(arr[i] < pivot){
                smallGrpEnd++;
                Commons::swap(&arr[smallGrpEnd], &arr[i]);
            }
        }
        
        Commons::swap(&arr[smallGrpEnd+1], &arr[pivotIdx]);
        workStack.push(startIdx);
        workStack.push(smallGrpEnd);
        workStack.push(smallGrpEnd+2);
        workStack.push(pivotIdx);
    }
}

