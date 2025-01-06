#include "utils.h"

void error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}