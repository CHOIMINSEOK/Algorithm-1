//
//  Commons.cpp
//  Algorithm#1
//
//  Created by Minseok Choi on 08/10/2017.
//  Copyright © 2017 Minseok Choi. All rights reserved.
//

#include <stdio.h>
#include "Commons.h"

void Commons::swap(int *val1, int *val2){
    int tmp;
    
    tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}
