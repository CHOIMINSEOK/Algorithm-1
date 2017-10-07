//
//  main.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 07/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include <iostream>
#include "SortUtils.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    SortUtils sortUtils;
    sortUtils.openInputStream("/Users/lf_wannabe/Algorithm/Algorithm#1/Algorithm#1/input.txt");
    sortUtils.closeInputStream();

    return 0;
}
