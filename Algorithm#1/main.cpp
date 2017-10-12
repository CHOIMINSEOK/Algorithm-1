//
//  main.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 07/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include <iostream>
#include <vector>
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
class SortResult {
public:
    float time;
    string content;
    SortResult(float t, string c);
};
SortResult::SortResult(float t, string c){
    time = t;
    content = c;
}

bool operator <(const SortResult &a, const SortResult &b){
    return a.time < b.time;
}

void sortUsingAll(){
    vector<SortResult> rank;
//    sortUtils.insertionSort();
//    rank.push_back(SortResult(sortUtils.getProcessTime(), "insertionSort 걸린시간         : " + to_string(sortUtils.getProcessTime())));
//    sortUtils.bubbleSort();
//    rank.push_back(SortResult(sortUtils.getProcessTime(), "bubbleSort 걸린시간            : " + to_string(sortUtils.getProcessTime())));
//    sortUtils.selectionSort();
//    rank.push_back(SortResult(sortUtils.getProcessTime(), "selectionSort 걸린시간         : " + to_string(sortUtils.getProcessTime())));
    sortUtils.sqMergeSort();
    rank.push_back(SortResult(sortUtils.getProcessTime(), "sequential Merge Sort 걸린시간 : " + to_string(sortUtils.getProcessTime())));
    sortUtils.reMergeSort();
    rank.push_back(SortResult(sortUtils.getProcessTime(), "recursive Merge Sort 걸린시간  : " + to_string(sortUtils.getProcessTime())));
//    sortUtils.sqQuickSort();
//    rank.push_back(SortResult(sortUtils.getProcessTime(), "sequential Quick Sort 걸린시간 : " + to_string(sortUtils.getProcessTime())));
//    sortUtils.reQuickSort();
//    rank.push_back(SortResult(sortUtils.getProcessTime(), "recursive Quick Sort 걸린시간  : " + to_string(sortUtils.getProcessTime())));
    sortUtils.HeapSort();
    rank.push_back(SortResult(sortUtils.getProcessTime(), "HeapSort 걸린시간              : " + to_string(sortUtils.getProcessTime())));
    
    sort(rank.begin(), rank.end());
    for (int i = 0; i < rank.size(); i++)
        cout << rank[i].content << endl;
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
    cout << " 9. run all" << endl;
    cout << " 10. quit" << endl;
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
            case 9: sortUsingAll(); break;
            default: isRun = false; break;
        }
        getchar();
        getchar();
    }
    
    sortUtils.closeInputStream();

    return 0;
}





