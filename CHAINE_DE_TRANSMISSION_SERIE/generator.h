#include "systemc.h"

SC_MODULE(Generator)
{

  sc_in<bool> a;
  sc_in<bool> clock;
  sc_fifo<sc_uint<8>> din[8];
  sc_out<bool> b;
  
  void genere();

  SC_CTOR(Generator){
    SC_THREAD(genere);
  }
};
