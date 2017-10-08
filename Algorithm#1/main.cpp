//
//  main.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 07/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include <iostream>
#include "SortUtils.hpp"

static SortUtils sortUtils;
void insertSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.insertionSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
void bubbleSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.bubbleSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
void selectSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.selectionSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
//void sqMergeSort(){
//    cout << "array : " + sortUtils.int2char(sortUtils.sqMergeSort()) << endl;
//    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
//}
//void reMergeSort(){
//    cout << "array : " + sortUtils.int2char(sortUtils.reMergeSort()) << endl;
//    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
//}
void sqQuickSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.sqQuickSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
void reQuickSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.reQuickSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
//void HeapSort(){
//    cout << "array : " + sortUtils.int2char(sortUtils.HeapSort()) << endl;
//    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
//}

int main(int argc, const char * argv[]) {
    if(sortUtils.openInputStream("input.txt") == -1){
        cout << "파일을 여는데 실패하였습니다. " << endl;
        return 0;
    }
    
//    insertSort();
//    bubbleSort();
//    selectSort();
//    reMergeSort();
//    sqMergeSort();
//    reQuickSort();
    sqQuickSort();
//    HeapSort();
    sortUtils.closeInputStream();

    return 0;
}





