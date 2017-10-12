//
//  MergeSort.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 08/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include "MergeSort.hpp"

/* recursive Merge Sort
 *  - ppt pseudo code를 참조하였습니다.
 */
int* MergeSort::recurSort(int *arr, int startIdx, int endIdx){
    int arrSize = endIdx - startIdx + 1;
    if(arrSize < 2) return new int[2]{2, arr[startIdx]};
    
    int pivot = startIdx + arrSize/2 - 1;
    int* partition1 = recurSort(arr, startIdx, pivot);
    int* partition2 = recurSort(arr, pivot+1, endIdx);
    
    return merge(partition1, partition2);
}

/* sequential Merge Sort
 *  - 자료구조 queue를 활용하여 구현하였습니다.
 *  - sequential merge sort의 경우 처음에 진행하는 divide을
 *  - queue에 각각의 데이터를 하나씩 넣는 for문으로 대체할 수 있었습니다.
 *  - queue에 데이터를 모두 넣은 후, 2개씩 pop()하여 merge하고 다시 push하면서,
 *  - queue에 1개의 배열이 존재할때까지 진행하도록하여 구현하였습니다.
 */
int* MergeSort::seqSort(int *arr){
    int* partition1, *partition2;
    queue<int*> workQueue;
    
    // divide 부분 입니다.
    for (int i=1; i<arr[SIZE]; i++) {
        workQueue.push(new int[2]{2, arr[i]});
    }
    
    // queue에 1개의 배열이 남을 때까지 2개씩 pop()하고 merge하여 push()합니다.
    while(workQueue.size() > 1){
        partition1 = workQueue.front(); workQueue.pop();
        partition2 = workQueue.front(); workQueue.pop();
        
        workQueue.push(merge(partition1, partition2));
    }
    
    int* newArr = workQueue.front(); workQueue.pop();
    return newArr;
    
}

int* MergeSort::merge(int *arr1, int *arr2){
    int arr1Size = arr1[SIZE], arr2Size = arr2[SIZE];
    int newArrSize = arr1Size + arr2Size - 1;
    int* newArr = new int[newArrSize];
    int arr1CurIdx = 1, arr2CurIdx = 1;
    
    newArr[SIZE] = newArrSize;
    
    for (int i=1; i<newArrSize; i++) {
        // arr1가 새로운 배열에 모두 추가됬을 때
        if(arr1CurIdx >= arr1Size){
            newArr[i] = arr2[arr2CurIdx++];
            continue;
        }
        // arr2가 새로운 배열에 모두 추가됬을 때
        if(arr2CurIdx >= arr2Size){
            newArr[i] = arr1[arr1CurIdx++];
            continue;
        }
        
        newArr[i] = arr1[arr1CurIdx] < arr2[arr2CurIdx] ? arr1[arr1CurIdx++] : arr2[arr2CurIdx++];
    }
    
    delete[] arr1;
    delete[] arr2;
    return newArr;
    
}
