#ifndef TIME_H
#define TIME_H

#ifdef __unix__
#include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

#include <stdio.h>
#include <time.h>
#include <unistd.h>

void timer()
{

    // scanf("%d", &minutes);
    for (int i = 0; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            sleep(1); // sleep for 1 second
        }
    }
}

#endif