#include "generator.h"


void Generator::genere(){
    

    if(din->num_free() != 0){// La FIFO n'est pas pleine
        din->write(a.read());
        wait(10,SC_MS);
    }

    b.write(din->read());
}