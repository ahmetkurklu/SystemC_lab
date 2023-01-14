#include "MAX2.h"

void Max2::maximum(){

    if(e1.read() > e2.read()){
        s.write(e1.read());
    }
    else{
        s.write(e2.read());
    }
}