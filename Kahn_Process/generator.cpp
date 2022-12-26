#include "generator.h"

void Generator::generating()
{
    cnt = 1;
    while(true)
    {
        output.write(cnt);
        cnt ++;
        wait(50, SC_NS);
    }
}