#ifndef RECOG
#define RECOG
#include"systemc.h"

SC_MODULE(Recog){

    sc_in<bool> e;
    sc_in<bool> h;
    sc_in<bool> rst;
    sc_out<bool> e;

    void recconaisseur();

    SC_CTOR(Recog){
        SC_METHOD(recconaisseur);
        sensitive << h.pos();
    }
};
#endif