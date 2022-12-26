#ifndef GENERATOR
#define GENERATOR

#include "systemc.h"

SC_MODULE(Generator){

    sc_fifo_out<int> output;

    int cnt;
    void generating();

    SC_CTOR(Generator){
        SC_THREAD(generating);
    }
};

#endif