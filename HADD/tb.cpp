#include "systemc.h"
#include "Half_add.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> a;
    sc_signal<bool> b;
    sc_signal<bool> s;
    sc_signal<bool> c;

    Half_Add myhadd("h1");
    myhadd.A(a);
    myhadd.B(b);
    myhadd.S(s);
    myhadd.C(c);

    Monitor mon("m1");
    mon(a,b,s,c);

    sc_trace_file *trace_file = sc_create_vcd_trace_file("tb");
    sc_trace(trace_file, a, "A");
    sc_trace(trace_file, b, "B");
    sc_trace(trace_file, s, "S");
    sc_trace(trace_file, c, "C");

    a = 0;
    b = 0;
    sc_start(10, SC_NS);
    a = 0;
    b = 1;
    sc_start(10, SC_NS);
    a = 1;
    b = 0;
    sc_start(10, SC_NS);
    a = 1;
    b = 1;
    sc_start(10, SC_NS);

    sc_close_vcd_trace_file(trace_file);

    return EXIT_SUCCESS;
}
