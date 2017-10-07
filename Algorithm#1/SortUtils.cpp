//
//  SortUtils.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 07/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include "SortUtils.hpp"
//http://www.cplusplus.com/doc/tutorial/files/ 참고함
int SortUtils::openInputStream(string fileName){
    fileInputStream.open(fileName, ios::in|ios::ate);
    streampos size;
    char * s;
    
    if(fileInputStream.is_open()){
        size = fileInputStream.tellg();
        s = new char[size + (streampos)1];
        fileInputStream.seekg(0, ios::beg);
        fileInputStream.read(s, size);
        s[size] = 0;
        
        cout << fileName + " 내용 : " + s << endl;
        
        delete[] s;
    } else {
        cout << fileName + "이 존재하지 않습니다. " << endl;
    }
    
    return 0;
}

int SortUtils::closeInputStream(){
    fileInputStream.close();
    return 0;
}
