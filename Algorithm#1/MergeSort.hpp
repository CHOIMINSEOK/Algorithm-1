//
//  MergeSort.hpp
//  Algorithm#1
//
//  Created by Minseok Choi on 08/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <queue>
#include "Commons.h"

class MergeSort{
private:
    static int* merge(int* arr1, int* arr2);
    
public:
    // recursive Merge Sort
    static int* recurSort(int* arr, int startIdx, int  endIdx);
    // sequential Merge Sort
    static int* seqSort(int* arr);
};

#endif /* MergeSort_hpp */
