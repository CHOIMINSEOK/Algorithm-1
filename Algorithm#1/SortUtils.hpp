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

using namespace std;

class SortUtils {
private:
    ifstream fileInputStream;
    double processTime;

public:
    int openInputStream(string fileName);
    int closeInputStream();
    
    int* char2int(char* oriArr);
    int CountChar(char* src, char tok);
    
    
};

#endif /* SortUtils_hpp */
