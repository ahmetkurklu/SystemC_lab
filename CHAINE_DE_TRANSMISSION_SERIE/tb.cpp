#include "systemc.h"
#include "generator.h"

int sc_main(int argc, char *argv[])
{
    sc_clock clk("clk", 10, SC_NS);
    sc_signal<bool> a;
    sc_signal<bool> b;


    return EXIT_SUCCESS;
}
