#ifndef GENERATOR
#define GENERATOR

#include "systemc.h"

SC_MODULE(Generator){

  sc_fifo_out<sc_bv<8>> output;


  void generating();

  SC_CTOR(Generator){
    SC_THREAD(generating);
  }

};

#endif