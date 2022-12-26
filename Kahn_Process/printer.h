#ifndef PRINTER
#define PRINTER

#include "systemc.h"

SC_MODULE(Printer){
    sc_fifo_in<int> input;

    void printing();

    SC_CTOR(Printer){
        SC_THREAD(printing);
    }
};

#endif