#include "systemc.h"
#include "generator.h"
#include "adder.h"
#include "forker.h"
#include "printer.h"

int sc_main(int argc, char *argv[])
{
    //FIFO
    sc_fifo <int> f1,f2,f3,f4; 
    // MODULES
    Generator gen("Generator");
    Adder add("Adder");
    Forker fork("Forker");
    Printer prnt("Printer");

    //Connexions
    gen.output(f1);
    add.input1(f1);
    add.input2(f3);
    add.output(f2);
    fork.input(f2);
    fork.output1(f3);
    fork.output2(f4);
    prnt.input(f4);

    //Run
    sc_start(500, SC_NS);

    return 0;
}
