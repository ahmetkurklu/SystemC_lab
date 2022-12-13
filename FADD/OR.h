#include "systemc.h"

SC_MODULE(OR_P)
{
  sc_in<bool> A;
  sc_in<bool> B;
  sc_out<bool> S;

  void or_();

  SC_CTOR(OR_P){
    SC_METHOD(or_);
    sensitive << A << B ;
  }
};