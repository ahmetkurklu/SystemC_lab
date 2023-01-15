#include "systemc.h"
#include "RECOG.h"

int sc_main(int argc, char *argv[])
{

    sc_signal<bool> e;
    sc_clock h("clk", 5, SC_NS);
    sc_signal<bool> rst;
    sc_signal<bool> s;

    Recog myrecog("rcg1");
    myrecog(e,h,rst,s);

    sc_trace_file *trace_file = sc_create_vcd_trace_file("tb");
    sc_trace(trace_file, e, "e");
    sc_trace(trace_file, h, "clk");
    sc_trace(trace_file, rst, "RST");
    sc_trace(trace_file, s, "S");



    e = 0;
    rst = 1;
    sc_start(10, SC_NS);
    rst = 0;
    sc_start(10, SC_NS);
    e=1;
    sc_start(10, SC_NS);
    e = 0;
    sc_start(10, SC_NS);
    e = 1;
    sc_start(40, SC_NS);
    e = 0;
    sc_start(40, SC_NS);
    e = 1;
    sc_start(15, SC_NS);
    e = 0;
    sc_start(5, SC_NS);
    e = 1;
    sc_start(50, SC_NS);

    sc_close_vcd_trace_file(trace_file);

    return EXIT_SUCCESS;
}

