#ifndef RX
#define RX

#include "systemc.h"

typedef
    enum{E_wait,E_lecture,E_parite,E_end} t_etat;

SC_MODULE(Rx){

    sc_fifo_in<sc_logic> TxD;
    sc_fifo_out<sc_lv<9>> output;
    sc_in<bool> clock;

    t_etat etat;

    void reception();

    SC_CTOR(Rx){

        etat = E_wait;
        SC_THREAD(reception);
        sensitive << clock.pos();
    }

};

#endif