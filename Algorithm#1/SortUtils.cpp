//
//  SortUtils.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 07/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include "SortUtils.hpp"
int* SortUtils::char2int(char* charArr){
    char* tok = " ";
    int intArraySize = CountChar(charArr, tok[0]) + 1;
    int* intArr = new int[intArraySize];
    char* charNums = strtok(charArr, tok);
    
    for(int i=0; charNums != NULL && i<intArraySize; i++){
        intArr[i] = atoi(charNums);
        charNums = strtok(NULL, tok);
    }
    
    return intArr;
}

int SortUtils::CountChar(char* src, char tok){
    int totalSize = strlen(src), findCount = 0;
    cout << "totalSize = " << totalSize << endl;
    for(int i = 0; i < totalSize; i++){
        if(src[i] == tok) findCount++;
    }
    return findCount;
}

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
        
        cout << "파일이름 : " + fileName << endl;
        cout << "char array : " << s << endl;
        
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
