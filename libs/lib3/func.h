#ifndef FUNC_H
#define FUNC_H

#include <stdint.h>
#ifdef USE_FUNC1
#include "func1.h"
#else
#include "func2.h"
#endif

void myPrint(const char* str);

#endif