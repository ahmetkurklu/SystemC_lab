#include "systemc.h"
#include "GENSEQ.h"

int sc_main(int argc, char *argv[])
{

    sc_clock h("clk", 5, SC_NS);
    sc_signal <bool> rst;
    sc_signal <sc_bv<3>> s;

    Genseq mygenseq("gen1");
    mygenseq(h,rst,s);

    sc_trace_file *trace_file = sc_create_vcd_trace_file("tb");
    sc_trace(trace_file, h, "CLK");
    sc_trace(trace_file, rst, "RST");
    sc_trace(trace_file, s, "S");



    rst = 1;
    sc_start(10, SC_NS);
    rst = 0;
    sc_start(150, SC_NS);
    rst = 1;
    sc_start(10, SC_NS);
    rst = 0;
    sc_start(150, SC_NS);

    sc_close_vcd_trace_file(trace_file);

    return EXIT_SUCCESS;
}

