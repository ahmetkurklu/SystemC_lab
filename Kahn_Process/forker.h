#include "systemc.h"

SC_MODULE(Forker)
{
    sc_fifo_in<int> input;
    sc_fifo_out<int> output1, output2;

    void forking();

    SC_CTOR(Forker){
        SC_THREAD(forking);
    }
};