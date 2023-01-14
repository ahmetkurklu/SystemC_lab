#include "systemc.h"
#include "MAX2.h"


int sc_main(int argc, char *argv[])
{

    sc_signal<sc_int<64>> e1;
    sc_signal<sc_int<64>> e2;
    sc_signal<sc_int<64>> s;

    Max2 mymax2("m1");
    mymax2.e1(e1);
    mymax2.e2(e2);
    mymax2.s(s);


    sc_trace_file *trace_file = sc_create_vcd_trace_file("tb");
    sc_trace(trace_file, e1, "E1");
    sc_trace(trace_file, e2, "E2");
    sc_trace(trace_file, s, "S");

    e1 = 10;
    e2 = 15;
    sc_start(10, SC_NS);
    e1 = 25;
    e2 = 15;
    sc_start(10, SC_NS);
    e1 = 3;
    e2 = 8;
    sc_start(10, SC_NS);
    e1 = 43;
    e2 = 15;
    sc_start(10, SC_NS);

    sc_close_vcd_trace_file(trace_file);

    return EXIT_SUCCESS;
}
