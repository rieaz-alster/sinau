#ifndef _LOG_H_
#define _LOG_H_

#ifndef EMBEDDED

#include <stdio.h>
#include <iostream>

void log(const char* ch)
{
    printf("%s", ch);
}

#else



#endif

#endif