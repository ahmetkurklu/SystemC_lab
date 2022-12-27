#include "generator.h"

void Generator::generating(){
    
    while(true){
        if(output.num_free() != 0){
            output.write("10101010");
        }
        wait(200,SC_NS);
    }
    
}