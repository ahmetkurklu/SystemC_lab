#include "OR.h"

void OR_P::or_()
{
    S.write(A.read() | B.read());
    
}