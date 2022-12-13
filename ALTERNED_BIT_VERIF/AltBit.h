#include "systemc.h"

typedef
  enum {E_start,E_0,E_1} t_etat;

SC_MODULE(AltBit)
{
  // Declaration des I/O
  sc_in<bool> E;
  sc_in<bool> clock;
  sc_out<bool> Err;
  
  // Declaration des etats
  t_etat etat;

  void verif();

  SC_CTOR(AltBit) {
    etat = E_start;
    SC_METHOD(verif);
    sensitive << clock.pos();
  }
};
