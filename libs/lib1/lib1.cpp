#include <stdio.h>
#include "lib1.h"

void myPrintFunction(int major, int minor, int patch, const char* version) {
    printf("> Enter myPrintFunction() in lib1\n");
    printf("\tHello, World! V%d.%d.%d (\"V%s\") \n", major, minor, patch, version);
    printf("< Exit myPrintFunction()\n");
}
