#include "TX.h"

void Tx::transmettre(){
    

    switch(etat){
        case E_wait:
            // On attend la réception d'un octet
            tmp = input.read();
            if(tmp == NULL){
                TxD.write(SC_LOGIC_1);
            }
            else{
                etat = E_send;
                TxD.write(SC_LOGIC_0);
                //XOR sur tout les bits pour détéminer la parité 
                parity = tmp.xor_reduce();
                i = 0;
            }
            break;
        case E_send:
            if(i < 8){
                //registre a décalge pour envoyer les bits un par un 
                TxD.write(tmp[7]);
                tmp.range(7,1) = tmp.range(6,0);
                tmp[0] = 0;
            }
            else{
                etat = E_parite;
                //Envoi du bit de parité a la fin
                TxD.write(parity);
            }
            break;
        case E_parite:
            // Retour a l'état attente 
            etat = E_wait;
            TxD.write(SC_LOGIC_1);
            break;
    }
}