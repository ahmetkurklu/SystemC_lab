#include "systemc.h"
#include "Half_add.h"
#include "OR.h"

SC_MODULE(Full_Add)
{
  sc_in<bool> A;
  sc_in<bool> B;
  sc_in<bool> CI;
  sc_out<bool> S;
  sc_out<bool> CO;

  Half_Add hadd1;
  Half_Add hadd2;
  OR_P or1;

  sc_signal<bool> S1;
  sc_signal<bool> C1;
  sc_signal<bool> C2;


  SC_CTOR(Full_Add): hadd1("HADD1"),hadd2("HADD2"), or1("OR1") {
    
    hadd1.A(A);
    hadd1.B(B);
    hadd1.S(S1);
    hadd1.C(C1);

    hadd2.A(S1);
    hadd2.B(CI);
    hadd2.S(S);
    hadd2.C(C2);

    or1.A(C1);
    or1.B(C2);
    or1.S(CO);

    sensitive << A << B << CI ;
  }
};