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

int main(int argc, const char * argv[]) {
    if(sortUtils.openInputStream("input.txt") == -1){
        cout << "파일을 여는데 실패하였습니다. " << endl;
        return 0;
    }
    
//    insertSort();
    bubbleSort();
    sortUtils.closeInputStream();

    return 0;
}





