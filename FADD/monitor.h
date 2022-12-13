#include <systemc.h>

SC_MODULE(Monitor){
    sc_in<bool> a;
    sc_in<bool> b;
    sc_in<bool> ci;
    sc_in<bool> s;
    sc_in<bool> co;

    sc_in<bool> s1;
    sc_in<bool> c1;
    sc_in<bool> c2;




    void print(){
        cout << "T = "<< sc_time_stamp()<< endl;
        cout<<"HADD 1 " <<" A ="<<a<<" B ="<<b<<" S1 ="<<s1<<" C1 ="<<c1<<endl;
        cout<<"HADD 2 " <<" S1 ="<<s1<<" CI ="<<ci<<" S ="<<s<<" C2 ="<<c2<<endl;
        cout<<"OR " <<" C1 ="<<c1<<" C2 ="<<c2<<" CO ="<<co <<endl;
    }

    SC_CTOR(Monitor){
        SC_METHOD(print);
        sensitive << a << b << ci;
    }

};