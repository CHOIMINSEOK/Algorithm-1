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

using namespace std;

class SortUtils {
private:
    ifstream fileInputStream;
    double processTime;

public:
    int openInputStream(string fileName);
    int closeInputStream();
    
};

#endif /* SortUtils_hpp */
