#include "systemc.h"
#include "CDCNT.h"

int sc_main(int argc, char *argv[])
{
    sc_clock clk("clk", 10, SC_NS);
    sc_signal <bool> lc;
    sc_signal <bool> ud;
    sc_signal <sc_int<9>> d;
    sc_signal <bool> cb;
    sc_signal <sc_int<9>> q;


    Cdcnt mycdcnt("cnt1");
    mycdcnt(clk,lc,ud,d,cb,q);
   

    sc_trace_file *trace_file = sc_create_vcd_trace_file("tb");
    sc_trace(trace_file, clk, "clk");
    sc_trace(trace_file, lc, "LC");
    sc_trace(trace_file, ud, "UD");
    sc_trace(trace_file, d, "D");
    sc_trace(trace_file, cb, "CB");
    sc_trace(trace_file, q, "Q");


    d = 5;
    lc = 0;
    ud = 0;
    sc_start(20, SC_NS);
    lc = 1;
    ud = 0;
    sc_start(80, SC_NS);
    ud = 1;
    sc_start(200, SC_NS);

    sc_close_vcd_trace_file(trace_file);

    return EXIT_SUCCESS;
}
