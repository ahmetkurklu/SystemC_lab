#include "systemc.h"

SC_MODULE(Half_Add)
{
  sc_in<bool> A;
  sc_in<bool> B;
  sc_out<bool> S;
  sc_out<bool> C;


  void hadd();

  SC_CTOR(Half_Add) {
    SC_METHOD(hadd);
    sensitive << A << B;
  }
};
