#ifndef MAX4
#define MAX4

#include "systemc.h"
#include "MAX2.h"

SC_MODULE(Max4){

    sc_in <sc_int<64>> e1;
    sc_in <sc_int<64>> e2;
    sc_in <sc_int<64>> e3;
    sc_in <sc_int<64>> e4;
    sc_out <sc_int<64>> s;


    Max2 m21;
    Max2 m22;
    Max2 m23;

    sc_signal <sc_int<64>> s1;
    sc_signal <sc_int<64>> s2;

    SC_CTOR(Max4): e1("e1"),e2("e2"),e3("e3"),e4("e4"),s("s"),m21("max21"),m22("max22"),m23("max23"){
        
        m21(e1,e2,s1);
        m22(e3,s1,s2);
        m23(e4,s2,s);

        sensitive << e1 << e2 << e3 << e4;

    }

};


#endif