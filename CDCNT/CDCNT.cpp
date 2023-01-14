#include "CDCNT.h"

void Cdcnt::cnt_dcnt(){

    if(lc.read() == 0){
        cnt.write(d.read());
        cb_tmp.write(0);
        
    }
    else{
        if(ud.read() == 0){
            if(cnt.read() == 9){
                cnt.write(0);
                cb_tmp.write(1);
            }
            else{
                cnt.write(cnt.read()+1);
                cb_tmp.write(0);
            }
        }
        else{
            if(cnt.read() == 0){
                cnt.write(9);
                cb_tmp.write(1);
            }
            else{
                cnt.write(cnt.read()-1);
                cb_tmp.write(0);
            }
        }
    }

    cb.write(cb_tmp.read());
    q.write(cnt.read());
}