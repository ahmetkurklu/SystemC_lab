#include "systemc.h"

SC_MODULE(Max2){

    sc_in <sc_int<64>> e1;
    sc_in <sc_int<64>> e2;
    sc_out <sc_int<64>> s;

    void maximum();

    SC_CTOR(Max2){
        SC_METHOD(maximum);
        sensitive << e1 << e2;
    }
};