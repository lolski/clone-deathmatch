#include "GetCurrentDateTime.h"

const std::string giveMeTheCurrentDateTimePlease() {
    time_t curDateTime = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&curDateTime);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
