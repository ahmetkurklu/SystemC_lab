#include "systemc.h"
#include "AltBit.h"

int sc_main(int argc, char *argv[])
{
    //Déclaration des signaux
    sc_clock clk("clk", 10, SC_NS,0.5,5,SC_NS);
    sc_signal<bool> err;
    sc_signal<bool> e;

    //Creation modul AltBit
    AltBit myAltbit("a1");
    myAltbit.clock(clk);
    myAltbit.Err(err);
    myAltbit.E(e);

    // Trace des signaux
    sc_trace_file *trace_file = sc_create_vcd_trace_file("tb");
    sc_trace(trace_file, clk, "clk");
    sc_trace(trace_file, err, "Err");
    sc_trace(trace_file, e, "E");

    //Variation de e
    e = 0;
    sc_start(10, SC_NS);
    e = 1;
    sc_start(10, SC_NS);
    e = 0;
    sc_start(20, SC_NS);
    e = 1;
    sc_start(30, SC_NS);
    int i;
    for(i = 0;i<20;i++){
        if(e == 0){
            e = 1;
            sc_start(10, SC_NS);
        }
        else{
            e = 0;
            sc_start(10, SC_NS);
        }
    }
    sc_close_vcd_trace_file(trace_file);

    return EXIT_SUCCESS;
}
