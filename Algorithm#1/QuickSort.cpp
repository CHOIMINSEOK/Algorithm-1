//
//  QuickSort.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 08/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include "QuickSort.hpp"

/* recursive Quick Sort
 *  - ppt pseudo code를 참조하였습니다.
 */
void QuickSort::recurSort(int *arr, int start, int end){
    if(start >= end) return;
    int pivot = arr[end];
    
    int smallGrpEnd = start-1;
    
    // 주어진 배열을 pivot을 기준으로 정렬합니다.
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


/*  sequential Quick Sort
 *  - 자료구조 stack를 활용하여 구현하였습니다.
 *  - while문을 stack이 empty한 상태가 될 때까지 돌게 하였고,
 *  - divide할 때마다 그 인덱스를 stack에 저장하도록 구현하였습니다.
 */
void QuickSort::seqSort(int *arr){
    int startIdx = 1;
    int pivotIdx = arr[SIZE] - 1;
    int smallGrpEnd, pivot;

    stack<int> workStack;
    
    // 정렬할 배열의 시작과 끝 index를 stack에 저장합니다.
    workStack.push(startIdx);
    workStack.push(pivotIdx);
    
    // stack이 빌 때까지 진행합니다.
    while(!workStack.empty()){
        pivotIdx = workStack.top(); workStack.pop();
        startIdx = workStack.top(); workStack.pop();
        
        if(startIdx >= pivotIdx) continue;
        
        smallGrpEnd = startIdx - 1;
        pivot = arr[pivotIdx];
        
        // 주어진 배열을 pivot을 기준으로 정렬합니다.
        for (int i=startIdx; i<pivotIdx+1; i++) {
            if(arr[i] < pivot){
                smallGrpEnd++;
                Commons::swap(&arr[smallGrpEnd], &arr[i]);
            }
        }
        
        Commons::swap(&arr[smallGrpEnd+1], &arr[pivotIdx]);
        // divide된 배열의 index를 다시 stack에 넣습니다. 
        workStack.push(startIdx);
        workStack.push(smallGrpEnd);
        workStack.push(smallGrpEnd+2);
        workStack.push(pivotIdx);
    }
}

