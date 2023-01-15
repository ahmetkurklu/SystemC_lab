#ifndef GENSEQ
#define GENSEQ

#include "systemc.h"

typedef
    enum {SO,S1,S2,S3,S4,S5} t_etat;

SC_MODULE(Genseq){

    sc_in <bool> h;
    sc_in <bool> rst;
    sc_out <sc_bv<3>> s;

    t_etat etat;

    void generateur();

    SC_CTOR(Genseq){
        etat = S0;
        SC_METHOD(generateur);
        sensitive << h.pos();
    } 
};

#endif