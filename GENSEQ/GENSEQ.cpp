#include "GENSEQ.h"

void Genseq::generateur(){

    if(rst.read() == 1){
        etat = S0;
    }
    else{
        switch(etat){
            case S0:
                s.write("100");
                etat = S1;
                break;
            case S1:
                s.write("010");
                etat = S2;
                break;
            case S2:
                s.write("111");
                etat = S3;
                break;
            case S3:
                s.write("110");
                etat = S4;
                break;
            case S4:
                s.write("010");
                etat = S5;
                break;
            case S5:
                s.write("000");
                etat = S0;
                break;
        }
    }


}