#include "systemc.h"

SC_MODULE(Adder)
{
    sc_fifo_in<int> input1, input2;
    sc_fifo_out<int> output;

    void adding();

    SC_CTOR(Adder){

        SC_THREAD(adding);
    }
};