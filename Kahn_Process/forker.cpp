#ifndef FORKER
#define FORKER


#include "forker.h"

void Forker::forking(){
    output1.write(0);
    while (true){
        int value = input.read();
        output1.write(value);
        output2.write(value);
    }
}

#endif