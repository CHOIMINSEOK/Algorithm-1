//
//  SortUtils.hpp
//  Algorithm#1
//
//  Created by Minseok Choi on 07/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#ifndef SortUtils_hpp
#define SortUtils_hpp

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Commons.h"
#include "QuickSort.hpp"

class SortUtils {
private:
    ifstream fileInputStream;
    char* oriFileArr;
    float processTime;

public:
    int openInputStream(string fileName);
    int closeInputStream();
    
    double getProcessTime();
    
    /* utils */
    int* char2int(char* oriArr);
    string int2char(int* oriArr);
    int CountChar(char* src, char tok);
    int saveSortedArr(string oriArr);
    
    /* Sorting function */
    int* insertionSort();
    int* bubbleSort();
    int* selectionSort();
    int* sqQuickSort(); // sequence ver. of Quick sort
    int* reQuickSort(); // recursive ver. of Quick sort
    int* sqMergeSort(); // sequence ver. of Merge sort
    int* reMergeSort(); // recursive ver. of Merge sort
    int* HeapSort();
};

#endif /* SortUtils_hpp */
