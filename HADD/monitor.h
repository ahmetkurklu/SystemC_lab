#include <systemc.h>

SC_MODULE(Monitor){
    sc_in<bool> a;
    sc_in<bool> b;
    sc_in<bool> s;
    sc_in<bool> c;

    void print(){
        cout << "T = "<< sc_time_stamp()<<" A = "<<a<<" B = "<<b <<" S = "<< s << " C = "<<c<<endl;
    }

    SC_CTOR(Monitor){
        SC_METHOD(print);
        sensitive << a << b << s << c;
    }

};