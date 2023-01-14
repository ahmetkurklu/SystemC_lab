#include "systemc.h"
#include "MAX4.h"

int sc_main(int argc, char *argv[])
{
    sc_signal<sc_int<64>> e1;
    sc_signal<sc_int<64>> e2;
    sc_signal<sc_int<64>> e3;
    sc_signal<sc_int<64>> e4;
    sc_signal<sc_int<64>> s;

    Max4 m4("m1");
    m4.e1(e1);
    m4.e2(e2);
    m4.e3(e3);
    m4.e4(e4);
    m4.s(s);

    sc_trace_file *trace_file = sc_create_vcd_trace_file("tb");
    sc_trace(trace_file, e1, "E1");
    sc_trace(trace_file, e2, "E2");
    sc_trace(trace_file, e3, "E3");
    sc_trace(trace_file, e4, "E4");
    sc_trace(trace_file, s, "S");



    e1 = 10;
    e2 = 25;
    e3 = 15;
    e4 = 15;
    sc_start(10, SC_NS);
    e1 = 8;
    e2 = 21;
    e3 = 7;
    e4 = 32;
    sc_start(10, SC_NS);
    e1 = 43;
    e2 = 50;
    e3 = 10;
    e4 = 20;
    sc_start(10, SC_NS);
    e1 = 10;
    e2 = 15;
    e3 = 15;
    e4 = 15;
    sc_start(10, SC_NS);
    e1 = 1;
    e2 = 7;
    e3 = 2;
    e4 = 3;
    sc_start(10, SC_NS);
    sc_close_vcd_trace_file(trace_file);

    return EXIT_SUCCESS;
}

