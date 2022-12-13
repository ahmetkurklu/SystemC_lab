#include "AltBit.h"

void AltBit::verif(){
  
  switch(etat){
    case E_start:
      if(E.read() == 1){
        etat = E_1;
        Err.write(0);
      }
      else{
        etat = E_0;
        Err.write(0);
      }
      break;
    case E_0:
      if(E.read() == 1){
        etat = E_1;
        Err.write(0);
      }
      else{
        Err.write(1);
      }
      break;
    case E_1:
      if(E.read() == 1){
        Err.write(1);
      }
      else{
        etat = E_0;
        Err.write(0);
      }
      break;
  }
}