#ifndef RECOG
#define RECOG
#include"systemc.h"

typedef
    enum {Start,E1,E2,E3} t_etat;


SC_MODULE(Recog){

    sc_in<bool> e;
    sc_in<bool> h;
    sc_in<bool> rst;
    sc_out<bool> s;

    t_etat etat;

    void recconaisseur();

    SC_CTOR(Recog){
        etat = Start;
        SC_METHOD(recconaisseur);
        sensitive << h.pos();
    }
};
#endif