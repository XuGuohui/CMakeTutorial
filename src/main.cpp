#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "config.h"
#include "lib1.h"
#include "lib2.h"
#include "func.h"

int main() {
    // printf("Hello, World! V%d.%d.%d (\"V%s\") \n", PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH, PROJECT_VERSION);
    myPrintFunction(PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH, PROJECT_VERSION);
    myPlus(1, 2);
    myPrint("Hello");

    // while (true) {
    //     ;
    // }

    return 0;
}