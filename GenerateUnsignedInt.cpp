#include "GenerateUnsignedInt.h"

int generateUnsignedInt() {
    static int i = 0;
    i++;
    return i;
}
