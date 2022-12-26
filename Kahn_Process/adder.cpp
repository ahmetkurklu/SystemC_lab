#include "adder.h"

void Adder::adding(){
    while(true){
        output.write(input1.read() + input2.read());
    }
}