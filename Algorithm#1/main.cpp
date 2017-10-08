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
void sqMergeSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.sqMergeSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
void reMergeSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.reMergeSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
void sqQuickSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.sqQuickSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
void reQuickSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.reQuickSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
void HeapSort(){
    cout << "array : " + sortUtils.int2char(sortUtils.HeapSort()) << endl;
    cout << "걸린 시간 : " << sortUtils.getProcessTime() << endl;
}
void showLandingPage(){
    system("clear");
    cout << "#####               Algorithm Assignment #1 " << endl;
    cout << "##########          implement and analyze each of sorting algorithms" << endl;
    cout << "###############     by CHOIMINSEOK\n" << endl;
    cout << " 1. Insertion Sort " << endl;
    cout << " 2. Bubble Sort " << endl;
    cout << " 3. Selection Sort " << endl;
    cout << " 4. Recursive Merge Sort " << endl;
    cout << " 5. Sequencial Merge Sort " << endl;
    cout << " 6. Recursive Quick Sort " << endl;
    cout << " 7. Sequencial Quick Sort " << endl;
    cout << " 8. Heap Sort " << endl;
    cout << " 9. quit" << endl;
    cout << "Selection : ";
}


int main(int argc, const char * argv[]) {
    if(sortUtils.openInputStream("input.txt") == -1){
        cout << "파일을 여는데 실패하였습니다. " << endl;
        return 0;
    }
    int selection;
    bool isRun = true;
    while(isRun){
        showLandingPage();
        cin >> selection;
        system("clear");
        
        switch (selection) {
            case 1: insertSort(); break;
            case 2: bubbleSort(); break;
            case 3: selectSort(); break;
            case 4: reMergeSort(); break;
            case 5: sqMergeSort(); break;
            case 6: reQuickSort(); break;
            case 7: sqQuickSort(); break;
            case 8: HeapSort(); break;
            default: isRun = false; break;
        }
        getchar();
        getchar();
    }
    
    sortUtils.closeInputStream();

    return 0;
}





