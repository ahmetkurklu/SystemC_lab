#ifndef TX
#define TX

#include "systemc.h"

typedef
  enum {E_wait,E_send,E_parite} t_etat;

SC_MODULE(Tx){

    //Declaration de I/O
    sc_fifo_in<sc_lv<8>> input;
    sc_fifo_out<sc_logic> TxD;
    sc_in<bool> clock;

    //Declaration des etats
    t_etat etat;

    sc_lv<8> tmp;
    sc_logic parity;
    sc_int<8> i;

    void transmettre();

    SC_CTOR(Tx){

        etat = E_wait;
        SC_THREAD(transmettre);
        sensitive << clock.pos();
    }
};
#endif