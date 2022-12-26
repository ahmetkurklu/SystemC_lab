#include "printer.h"

void Printer::printing(){

    while(true){
        int value = input.read();
        cout << sc_time_stamp() << " : " << value << endl;
    }
}