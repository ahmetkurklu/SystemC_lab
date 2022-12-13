#include "systemc.h"
#include "Full_add.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> a;
    sc_signal<bool> b;
    sc_signal<bool> ci;
    sc_signal<bool> s;
    sc_signal<bool> co;

    Full_Add myfadd("h1");
    myfadd.A(a);
    myfadd.B(b);
    myfadd.CI(ci);
    myfadd.S(s);
    myfadd.CO(co);

    sc_trace_file *trace_file = sc_create_vcd_trace_file("tb");
    sc_trace(trace_file, a, "A");
    sc_trace(trace_file, b, "B");
    sc_trace(trace_file, s, "S");
    sc_trace(trace_file, ci, "CI");
    sc_trace(trace_file, co, "CO");

    a = 0;
    b = 0;
    ci = 0;
    sc_start(10, SC_NS);
    a = 0;
    b = 0;
    ci = 1;
    sc_start(10, SC_NS);
    a = 0;
    b = 1;
    ci = 0;
    sc_start(10, SC_NS);
    a = 0;
    b = 1;
    ci = 1;
    sc_start(10, SC_NS);
    a = 1;
    b = 0;
    ci = 0;
    sc_start(10, SC_NS);
    a = 1;
    b = 0;
    ci = 1;
    sc_start(10, SC_NS);
    a = 1;
    b = 1;
    ci = 0;
    sc_start(10, SC_NS);
    a = 1;
    b = 1;
    ci = 0;
    sc_start(10, SC_NS);

    sc_close_vcd_trace_file(trace_file);

    return EXIT_SUCCESS;
}