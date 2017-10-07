//
//  SortUtils.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 07/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include "SortUtils.hpp"

int* SortUtils::insertionSort(){
    int* arr = char2int(oriFileArr);
    int totalSize = arr[SIZE];
    int tmp;
    clock_t begin, end;
    
    begin = clock();
    for (int i=2; i<totalSize; i++) {
        tmp = arr[i];
        int j;
        for (j=i-1; j>0 && arr[j]>tmp; j--) {
            arr[j+1] = arr[j];
        }
        
        arr[j+1] = tmp;
    }
    end = clock();
    processTime = (float)(end-begin)/CLOCKS_PER_SEC;
    
    saveSortedArr(int2char(arr));
    return arr;
}

int* SortUtils::bubbleSort(){
    int* arr = char2int(oriFileArr);
    int totalSize = arr[SIZE];
    int tmp;
    clock_t begin, end;
    
    begin = clock();
    for (int i=1; i<totalSize-1; i++) {
        for (int j=1; j<totalSize-i; j++) {
            if(arr[j] > arr[j+1]){
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    end = clock();
    processTime = (float)(end-begin)/CLOCKS_PER_SEC;
    
    saveSortedArr(int2char(arr));
    return arr;
}

int* SortUtils::selectionSort(){
    int* arr = char2int(oriFileArr);
    int totalSize = arr[SIZE];
    int tmp, minIdx;
    clock_t begin, end;
    
    begin = clock();
    for (int i=1; i<totalSize; i++) {
        minIdx = i;
        for (int j=i+1; j<totalSize; j++) {
            if(arr[minIdx] > arr[j]) minIdx = j;
        }
        
        if(minIdx != i){
            tmp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = tmp;
        }
    }
    
    end = clock();
    processTime = (float)(end-begin)/CLOCKS_PER_SEC;
    
    saveSortedArr(int2char(arr));
    return arr;
}

int* SortUtils::char2int(char* charArr){
    char* tok = " ";
    int intArraySize = CountChar(charArr, tok[0]) + 2;
    int* intArr = new int[intArraySize];
    char* charNums = strtok(charArr, tok);
    intArr[SIZE] = intArraySize;
    
    for(int i=1; charNums != NULL && i<intArraySize; i++){
        intArr[i] = atoi(charNums);
        charNums = strtok(NULL, tok);
    }
    
    return intArr;
}

string SortUtils::int2char(int *oriArr){
    string sortedArr = "";
    for (int i=1; i<oriArr[SIZE]; i++) {
        sortedArr += to_string(oriArr[i]) + " ";
    }
    
    return sortedArr;
}

int SortUtils::CountChar(char* src, char tok){
    int totalSize = strlen(src), findCount = 0;
    for(int i = 0; i < totalSize; i++){
        if(src[i] == tok) findCount++;
    }
    return findCount;
}

int SortUtils::saveSortedArr(string oriArr){
    ofstream outputFile("output.txt");
    outputFile << oriArr << endl;
    outputFile.close();
    
    return 0;
}

double SortUtils::getProcessTime(){
    return processTime;
}

int SortUtils::openInputStream(string fileName){
    fileInputStream.open(fileName, ios::in|ios::ate);
    streampos size;
    
    if(fileInputStream.is_open()){
        size = fileInputStream.tellg();
        oriFileArr = new char[size + (streampos)1];
        fileInputStream.seekg(0, ios::beg);
        fileInputStream.read(oriFileArr, size);
        oriFileArr[size] = 0;
        
    } else {
        return -1;
    }
    
    return 0;
}

int SortUtils::closeInputStream(){
    fileInputStream.close();
    delete[] oriFileArr;
    return 0;
}
