#include <stdio.h>
#include "func.h"

void myPrint(const char* str) {
#ifdef USE_FUNC1
    myPrint1(str);
#else
    myPrint2(str);
#endif
}
