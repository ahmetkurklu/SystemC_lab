#include "printer.h"

void Printer::printing(){

    int value = input.read();
    cout << sc_time_stamp() << " : " << value << endl;

}