#include"RECOG.h"

void Recog::recconaisseur(){

    if(rst.read() == 1){
        etat = Start;
        s.write(0);
    }
    else{
        switch(etat){
            case Start:
                if (e.read() == 1)
                {
                    etat = E1;
                    s.write(0);
                }
                else{
                    etat = Start;
                    s.write(0);
                }
                break;
            case E1:
                if (e.read() == 1)
                {
                    etat = E2;
                    s.write(0);
                }
                else{
                    etat = Start;
                    s.write(0);
                }
                break;
            case E2:
                if (e.read() == 1)
                {
                    etat = E3;
                    s.write(1);
                }
                else{
                    etat = Start;
                    s.write(0);
                }
                break;
            case E3:
                if (e.read() == 1)
                {
                    etat = E3;
                    s.write(1);
                }
                else{
                    etat = Start;
                    s.write(0);
                }
                break;
        }
    }
}