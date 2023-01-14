#ifndef CDCNT
#define CDCNT

#include "systemc.h"

SC_MODULE(Cdcnt){

    //Inputs
    sc_in <bool> clk;
    sc_in <bool> lc;
    sc_in <bool> ud;
    sc_in <sc_int<9>> d;

    //Outputs
    sc_out <bool> cb;
    sc_out <sc_int<9>> q;

    sc_signal <sc_int<9>> cnt;
    sc_signal <bool> cb_tmp;

    void cnt_dcnt();

    SC_CTOR(Cdcnt){
        SC_METHOD(cnt_dcnt);
        sensitive << clk.pos();
    }
};

#endif