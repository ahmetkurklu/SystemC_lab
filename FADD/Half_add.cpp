#include "Half_add.h"

void Half_Add::hadd()
{
    S.write(A.read() ^ B.read());
    C.write(A.read() & B.read()); 
}