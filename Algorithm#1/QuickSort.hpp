//
//  QuickSort.hpp
//  Algorithm#1
//
//  Created by Minseok Choi on 08/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include <stack>
#include "Commons.h"

class QuickSort{
public:
    // recursive Quick Sort
    static void recurSort(int* arr, int start, int end);
    // sequential Quick Sort
    static void seqSort(int* arr);
    
};

#endif /* QuickSort_hpp */
